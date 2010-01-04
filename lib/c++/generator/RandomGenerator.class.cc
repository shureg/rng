#include"rng/generator/RandomGenerator.class.h"
#include"rng/uig/UIG_Dictionary.class.h"
#include<fstream>
#include<string>
#include<iostream>
#include<stdexcept>
#include "boost/format.hpp"

#include "callback_log/LOG.h"

using namespace CALLBACK_LOG;

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

RandomGenerator::~RandomGenerator() {}

const UnitIntervalGenerator* RandomGenerator::uig_holder = 0;

lua_State* RandomGenerator::get_lua_State()
{
   static lua_State* l = luaL_newstate();

   return l;
}

void RandomGenerator::get_external_uig(
      const UnitIntervalGenerator* uig_input)
{
   RandomGenerator::uig_holder = uig_input;
}

const UnitIntervalGenerator* RandomGenerator::set_uig()
{
   lua_State* L = RandomGenerator::get_lua_State();
   
   luaL_openlibs(L);
   RandomGenerator::uig_holder = 0;

   const char* rng_lua_wrap_init_string =
      "require(\"rng_lua_swig_wrap\");"\
      "rng = rng_lua_swig_wrap";

   if( luaL_dostring(L,rng_lua_wrap_init_string) )
      LOG(EXCEPTION, boost::format(
	       "Exception caught while tryign to load the "\
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
      "rng.RandomGenerator_get_external_uig(UIG)";

   if( luaL_dostring(L,uig_assign_string) )
      LOG(EXCEPTION, boost::format("Exception caught while trying to run "\
	       "uig assignment command %s: %s")
	    % lua_cfg_file % (lua_tostring(L,-1))
	    );

   LOG(TRACE,boost::format("uig assignment performed\n"));

   if (RandomGenerator::uig_holder == 0)
      LOG(EXCEPTION, boost::format
	    ("The UnitIntervalGenerator pointer does not appear to have "\
	     "been properly initialised\n")
	    );

   try
   {
      double test = (*RandomGenerator::uig_holder)();
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

   return RandomGenerator::uig_holder;
}

const UnitIntervalGenerator* RandomGenerator::uig()
{
   static const UnitIntervalGenerator* dummy = RandomGenerator::set_uig();

   return dummy;
}

const double RandomGenerator::unit_interval_value() const
{
  return (*RandomGenerator::uig())(); 
}
