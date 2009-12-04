// =====================================================================================
// 
//       Filename:  UniformRatioGenerator.class.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  04/12/09 12:49:25
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#ifndef  UNIFORMRATIOGENERATOR_CLASS_INC
#define  UNIFORMRATIOGENERATOR_CLASS_INC

#include "rng/generator/TypedRandomGenerator.class.hpp"

namespace RNG
{
   //! A modification of acceptance-rejection algorithm that uses ratio of two uniform variates
   class UniformRatioGenerator: public TypedRandomGenerator<double>
   {
   public:

      const double operator() () const;

   protected:

      virtual double density(double) const = 0;

      /*! \f$ a_{+} := \sup x \sqrt{f(x)} \f$
       */
      virtual double a_plus() const = 0;

      /*! \f$ a_{-} := \inf x \sqrt{f(x)} \f$
       */
      virtual double a_minus() const = 0;

      /*! \f$ b{+} := \sup \sqrt{f(x)} \f$
       */
      virtual double b() const = 0;

      virtual const bool accept(double,double,double) const = 0;

      virtual const bool quick_accept(double,double,double) const = 0;

      virtual const bool quick_reject(double,double,double) const = 0;
   };
}

#endif   // ----- #ifndef UNIFORMRATIOGENERATOR_CLASS_INC  -----
