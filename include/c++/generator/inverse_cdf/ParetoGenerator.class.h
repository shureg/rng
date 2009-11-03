// =====================================================================================
// 
//       Filename:  ParetoGenerator.class.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  11/06/09 17:13:30
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#ifndef  _RNG_PARETOGENERATOR_CLASS_INC
#define  _RNG_PARETOGENERATOR_CLASS_INC

#include "rng/generator/inverse_cdf/InverseCDFGenerator.class.hpp"

namespace RNG
{
   class ParetoGenerator: public InverseCDFGenerator<double>
   {
   public:

      ParetoGenerator(double, double);

   protected:

      //! Minimal value
      double x_min;

      //! Shape coefficient
      /*! Greater values of k lead to smaller "inequity" 
       *  in the distribution
       */
      double k;

      const double InverseCDF(double) const;

      XmlField xml_description() const;

   private:

      ParetoGenerator();

   };
}

#endif   // ----- #ifndef _RNG_PARETOGENERATOR_CLASS_INC  -----
