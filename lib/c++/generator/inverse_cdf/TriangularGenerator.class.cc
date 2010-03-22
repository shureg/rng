// =====================================================================================
// 
//       Filename:  TriangularGenerator.class.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  22/03/10 14:47:55
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#include "rng/generator/inverse_cdf/TriangularGenerator.class.h"
#include <cmath>

using RNG::TriangularGenerator;

TriangularGenerator::TriangularGenerator(
      double min, double max, double mode):
   min(min), max(max), mode(mode),
   range(max-min), l_range(mode-min), u_range(max-mode),
   F_mode( l_range/range )
{}

const double TriangularGenerator::InverseCDF(double u) const
{
   if( u < F_mode )
      return min + sqrt(u*range*l_range);
   else
      return max - sqrt((1-u)*range*u_range);
}

XmlField TriangularGenerator::xml_description() const
{
   XmlField tmp("Triangular.Random.Generator");

   tmp("min") = min;
   tmp("max") = max;
   tmp("mode") = mode;

   return tmp;
}
