// =====================================================================================
// 
//       Filename:  LuaDiscreteTableGenerator.class.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  11/07/2010 04:18:14 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#ifndef  LUADISCRETETABLEGENERATOR_CLASS_INC
#define  LUADISCRETETABLEGENERATOR_CLASS_INC

#include "rng/generator/inverse_cdf/InverseCDFGenerator.class.hpp"

#include <map>

struct lua_State;

namespace RNG
{
   class LuaDiscreteTableGenerator: public InverseCDFGenerator<double>
   {
   public:

      LuaDiscreteTableGenerator(const char* cfg_filename,
	    const char* table_name = "table");

      XmlField xml_description() const;

   protected:

      lua_State* L;

      std::map<double,double> table;

      const double InverseCDF(double) const;

      COVARIANT_CLONE(LuaDiscreteTableGenerator)
   };
}

#endif   // ----- #ifndef LUADISCRETETABLEGENERATOR_CLASS_INC  -----
