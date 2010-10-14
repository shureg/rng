// =====================================================================================
// 
//       Filename:  todIntegerGenerator.class.hpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  10/10/2010 02:37:40 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#ifndef  TODINTEGERGENERATOR_CLASS_INC
#define  TODINTEGERGENERATOR_CLASS_INC

#include "rng/generator/inverse_cdf/TabulatedOnDemandGenerator.class.hpp"

namespace RNG
{
   template<typename T> class todIntegerGenerator: public TabulatedOnDemandGenerator<T>
   {
   public:

      todIntegerGenerator(const T& starting_discrete_value): 
	 TabulatedOnDemandGenerator<T>(starting_discrete_value){}

   protected:

      T next_discrete_value(const T& v) const {T u = v; return ++u;}

   };
}

#endif   // ----- #ifndef TODINTEGERGENERATOR_CLASS_INC  -----
