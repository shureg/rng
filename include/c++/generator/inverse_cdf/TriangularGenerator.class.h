// =====================================================================================
// 
//       Filename:  TriangularGenerator.class.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  22/03/10 14:44:18
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#ifndef  TRIANGULARGENERATOR_CLASS_INC
#define  TRIANGULARGENERATOR_CLASS_INC

#include "rng/generator/inverse_cdf/InverseCDFGenerator.class.hpp"

namespace RNG
{
   class TriangularGenerator: public InverseCDFGenerator<double>
   {
   public:

      TriangularGenerator(double min, double max, double mode);

      XmlField xml_description() const;

   protected:

      const double InverseCDF(double) const;

   private:

      double min, max, mode;

      TriangularGenerator();

      //! Auxilliary variables
      double range, l_range, u_range, F_mode;

   };
}

#endif   // ----- #ifndef TRIANGULARGENERATOR_CLASS_INC  -----
