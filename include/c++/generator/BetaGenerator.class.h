// =====================================================================================
// 
//       Filename:  BetaGenerator.class.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  22/03/10 13:21:53
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#ifndef  BETAGENERATOR_CLASS_INC
#define  BETAGENERATOR_CLASS_INC

#include "rng/generator/TypedRandomGenerator.class.hpp"
#include "rng/generator/UniformGenerator.class.h"

namespace RNG
{
   //! Generates \f$\Beta(a,b)\f$ random variates with an acceptance-rejection method
   /*! Uses the Cheng (1978) algorithm, as presented in Devroye
    */
   class BetaGenerator: public TypedRandomGenerator<double>
   {
   public:

      BetaGenerator(double a, double b);

      const double operator() () const;

      XmlField xml_description() const;

   private:

      BetaGenerator();

      static const double log_4;

      UniformGenerator UG;

      double a, b;

      //! Auxilliary instance-specific computational variables
      double s, lambda, u;

      //! Additional auxilliary computaitonal variables
      mutable double U1, U2, V, Y;

      COVARIANT_CLONE(BetaGenerator)
   };
}

#endif   // ----- #ifndef BETAGENERATOR_CLASS_INC  -----
