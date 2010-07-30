// =====================================================================================
// 
//       Filename:  init.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  09/07/10 22:09:06
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#ifndef  INIT_INC
#define  INIT_INC

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include "boost/thread.hpp"
#include "rng/uig/UnitIntervalGenerator.class.h"

namespace RNG
{
   extern boost::mutex init_mutex;

   extern boost::thread_specific_ptr< lua_State > ls;

   extern boost::thread_specific_ptr< UnitIntervalGenerator > uig;

   //! A function to process the uig value set in a Lua config file
   /*! This must be exposed to Lua via SWIG
    */
   void get_external_uig(UnitIntervalGenerator*);

   //! A function to initialise the pseudo-random generator
   /*! Must be called by the user at the beginning of each thread
    */
   void init();

   void cleanup();

   extern UnitIntervalGenerator* uig_holder;
}

#endif   // ----- #ifndef INIT_INC  -----
