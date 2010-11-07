// =====================================================================================
// 
//       Filename:  LuaDiscreteTableGenerator.class.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  11/07/2010 05:08:00 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#include "rng/generator/inverse_cdf/LuaDiscreteTableGenerator.class.h"

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

using namespace RNG;

LuaDiscreteTableGenerator::LuaDiscreteTableGenerator(const char* cfg_filename,
      const char* table_name)
{
   L = luaL_newstate();
   luaL_openlibs(L);

   if( luaL_dofile(L,cfg_filename) != 0 )
      LOG(EXCEPTION, boost::format(
	       "LuaDiscreteTableGenerator::LuaDiscreteTableGenerator : "\
	       "could not open Lua config file %s: %s\n")
	    % cfg_filename % (lua_tostring(L,-1))
	    );

   //push table onto the stack
   lua_getglobal(L, table_name);

   //start table traversal
   //note that table is at position -2 in the stack now
   lua_pushnil(L);

   double k,v;

   while(lua_next(L,-2) != 0)
   {
      k = lua_tonumber(L,-2);
      v = lua_tonumber(L,-1);
      table.insert(std::pair<double,double>(k,v));
      //pop the value, leave the key for lua_next
      lua_pop(L,1);
   }

   //pop the table
   lua_pop(L,1);

   lua_close(L);
}

const double LuaDiscreteTableGenerator::InverseCDF(double u) const
{
   return table.lower_bound(u)->second;
}

XmlField LuaDiscreteTableGenerator::xml_description() const
{
   XmlField tmp("Lua.Discrete.Table.Generator");

   for(std::map<double, double>::const_iterator
	 i = table.begin(); i !=  table.end(); ++i)
   {
      XmlField entry("entry");

      entry("value") = i->second;
      entry("probability") = i->first;

      tmp.add_field(entry);
   }

   return tmp;
}
