// =====================================================================================
// 
//       Filename:  UniformIntGenerator.class.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  02/03/10 17:04:50
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#ifndef  UNIFORMINTGENERATOR_CLASS_INC
#define  UNIFORMINTGENERATOR_CLASS_INC

#include "rng/generator/TypedRandomGenerator.class.hpp"
#include "rng/generator/UniformGenerator.class.h"

#include <map>

namespace RNG
{
   //! Generates random integers in semi-open range [begin, end)
   class UniformIntGenerator: public TypedRandomGenerator<int>
   {
   public:

      UniformIntGenerator(int begin, int end);

      const int operator() () const;

      XmlField xml_description() const;

   protected:

      int begin, end;

      std::map< double, int > lower_bounds;

      RNG::UniformGenerator U;

   };
}

#endif   // ----- #ifndef UNIFORMINTGENERATOR_CLASS_INC  -----
