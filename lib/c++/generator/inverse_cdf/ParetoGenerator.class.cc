// =====================================================================================
// 
//       Filename:  ParetoGenerator.class.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  11/06/09 17:18:22
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#include "rng/generator/inverse_cdf/ParetoGenerator.class.h"
#include <cmath>
#include <iostream>

using namespace RNG;
using namespace std;

ParetoGenerator::ParetoGenerator(double _x_min, double _k):
   x_min(_x_min), k(_k)
{}

const double ParetoGenerator::InverseCDF(double u) const
{
   return x_min/std::pow(u,1./k);
}

XmlField ParetoGenerator::xml_description() const
{
   XmlField tmp("Pareto_Random_Generator");
   tmp.add_field("minimal_value",x_min);
   tmp.add_field("exponent",k);

   return tmp;
}
