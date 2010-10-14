// =====================================================================================
// 
//       Filename:  todZetaGenerator.class.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  10/10/2010 02:41:36 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#ifndef  TODZETAGENERATOR_CLASS_INC
#define  TODZETAGENERATOR_CLASS_INC

#include "rng/generator/inverse_cdf/todIntegerGenerator.class.hpp"

namespace RNG
{
   class todZetaGenerator: public todIntegerGenerator<unsigned long>
   {
   public:

      todZetaGenerator(double shape, unsigned long min_value=1ul);

      ~todZetaGenerator(){}

      XmlField xml_description() const;

   protected:

      double shape;

      unsigned long min_value;

      double probability_mass_function(const unsigned long& k) const;

   private:

      unsigned long value_adjustment;
   };
}

#endif   // ----- #ifndef TODZETAGENERATOR_CLASS_INC  -----
