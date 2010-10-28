// =====================================================================================
// 
//       Filename:  urTGenerator.class.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  04/12/09 13:22:23
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#ifndef  URTGENERATOR_CLASS_INC
#define  URTGENERATOR_CLASS_INC

#include "rng/generator/uniform_ratio/UniformRatioGenerator.class.h"

namespace RNG
{
   class urTGenerator: public UniformRatioGenerator
   {
   public:

      urTGenerator(double);

      XmlField xml_description() const;

   protected:

      double density(double) const;

      double b() const;

      double a_plus() const;

      double a_minus() const;

      const bool accept(double,double,double) const;

      const bool quick_accept(double,double,double) const;

      const bool quick_reject(double,double,double) const;

      //! The T distribution shape parameter
      /* ! The \f$ \nu \f$ shape parameter. 
       * When \f$ \nu \in \mathbf{N} \f$ it is also 
       * referred to as the number of degrees of freedom.
       */
      double nu;

      double a_abs;

      COVARIANT_CLONE(urTGenerator)

   };
}

#endif   // ----- #ifndef URTGENERATOR_CLASS_INC  -----
