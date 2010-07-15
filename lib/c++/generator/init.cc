// =====================================================================================
// 
//       Filename:  init.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  09/07/10 22:11:16
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#include "rng/generator/init.h"
#include "boost/lambda/bind.hpp"
#include "callback_log/LOG.h"

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#define CONFIG_PREFIX_STR TO_STR(CONFIG_PREFIX)

#define TO_STR(s) TO_STR_HIDDEN(s)

#define TO_STR_HIDDEN(s) #s

using namespace RNG;

using namespace std;

using namespace CALLBACK_LOG;

boost::mutex RNG::init_mutex;

boost::thread_specific_ptr< lua_State > RNG::ls;

boost::thread_specific_ptr< UnitIntervalGenerator > RNG::uig;

UnitIntervalGenerator* RNG::uig_holder = 0;

void RNG::get_external_uig(
      UnitIntervalGenerator* uig_input)
{
   RNG::uig_holder = uig_input;
}

void RNG::init()
{
   boost::lock_guard<boost::mutex> init_lock(init_mutex);

   RNG::ls.reset( luaL_newstate() );

   lua_State* L = RNG::ls.get();
   
   luaL_openlibs(L);
   
   RNG::uig_holder = 0;

   const char* rng_lua_wrap_init_string =
      "require(\"rng_lua_swig_wrap\");"\
      "rng = rng_lua_swig_wrap";

   if( luaL_dostring(L,rng_lua_wrap_init_string) )
      LOG(EXCEPTION, boost::format(
	       "Exception caught while trying to load the "\
	       "Lua rng swig wrap module\n")
	    );

   string lua_cfg_file = 
      string(CONFIG_PREFIX_STR) + string("/etc/rng/uig.cfg.lua");

   if( luaL_dofile(L,lua_cfg_file.c_str()) )
      LOG(EXCEPTION, boost::format
	    ("Exception caught while trying to run uig Lua configuration "\
	     "file %s: %s\n") % lua_cfg_file % (lua_tostring(L,-1))
	     );

   LOG(TRACE,boost::format("Lua config script executed\n"));


   const char* uig_assign_string = 
      "rng.get_external_uig(UIG)";

   if( luaL_dostring(L,uig_assign_string) )
      LOG(EXCEPTION, boost::format("Exception caught while trying to run "\
	       "uig assignment command %s: %s")
	    % lua_cfg_file % (lua_tostring(L,-1))
	    );

   LOG(TRACE,boost::format("uig assignment performed\n"));

   if (RNG::uig_holder == 0)
      LOG(EXCEPTION, boost::format
	    ("The UnitIntervalGenerator pointer does not appear to have "\
	     "been properly initialised\n")
	    );

   try
   {
      double test = (*RNG::uig_holder)();
      LOG(TRACE,boost::format("Test uig call executed,returning value %f\n")
	    % test);
   }
   catch(...)
   {
      LOG(EXCEPTION, boost::format(
	       "An exception has been caught whilst trying to invoke "\
	       "the () operator of the UnitIntervalGenerator object")
	    );
   }

   uig.reset(uig_holder);

   boost::this_thread::at_thread_exit( boost::lambda::bind(RNG::cleanup) );
}

void RNG::cleanup()
{
   RNG::uig.release();
   lua_close( RNG::ls.release() );
}
