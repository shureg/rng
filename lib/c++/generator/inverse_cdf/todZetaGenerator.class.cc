// =====================================================================================
// 
//       Filename:  todZetaGenerator.class.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  10/10/2010 02:44:14 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#include "rng/generator/inverse_cdf/todZetaGenerator.class.h"
#include "gsl/gsl_sf_zeta.h"

using RNG::todZetaGenerator;

todZetaGenerator::todZetaGenerator(double shape, unsigned long min_value): 
   todIntegerGenerator<unsigned long>(min_value),
   shape(shape), min_value(min_value), value_adjustment(1ul - min_value)
{}

double todZetaGenerator::probability_mass_function(const unsigned long& k) const
{
   return pow(k+value_adjustment,-shape)/gsl_sf_zeta(shape);
}

XmlField todZetaGenerator::xml_description() const
{
   XmlField tmp("Zeta.Random.Generator");
   
   tmp("shape") = shape;
   tmp("min_value") = min_value;
   tmp("type") = "TabulatedOnDemandGenerator";

   return tmp;
}
