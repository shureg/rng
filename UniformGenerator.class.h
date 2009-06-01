// =====================================================================================
// 
//       Filename:  UniformGenerator.class.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  19/05/09 15:37:00
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================


#ifndef  _RNG_UNIFORMGENERATOR_CLASS_INC
#define  _RNG_UNIFORMGENERATOR_CLASS_INC

#include"TypedRandomGenerator.class.hpp"

namespace RNG
{
   class UniformGenerator: public TypedRandomGenerator<double>
   {
   public:

      UniformGenerator();

      UniformGenerator(double,double);

      const double operator() () const;

      void describe(std::ostream&) const;

   protected:

      double l;

      double u;

      bool is_std;

   };
}

#endif   // ----- #ifndef _RNG_UNIFORMGENERATOR_CLASS_INC  -----
