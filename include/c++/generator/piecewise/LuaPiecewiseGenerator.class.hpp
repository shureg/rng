// =====================================================================================
// 
//       Filename:  LuaPiecewiseGenerator.class.hpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  15/04/10 09:59:37
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#ifndef  LUAPIECEWISEGENERATOR_CLASS_INC
#define  LUAPIECEWISEGENERATOR_CLASS_INC

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

namespace RNG
{
   template<typename T> class LuaPiecewiseGenerator: public PiecewiseRandomGenerator<T>
   {
   public:

      LuaPiecewiseGenerator(const char* lua_filename);

   protected:

      lua_State* L;
   };
}

#endif   // ----- #ifndef LUAPIECEWISEGENERATOR_CLASS_INC  -----
