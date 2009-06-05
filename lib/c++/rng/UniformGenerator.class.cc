// =====================================================================================
// 
//       Filename:  UniformGenerator.class.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  19/05/09 15:48:30
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#include"rng/UniformGenerator.class.h"
#include"boost/format.hpp"
#include<iostream>

using namespace RNG;
using namespace std;

UniformGenerator::UniformGenerator(): l(0.), u(1.), is_std(true) {}

UniformGenerator::UniformGenerator(double _l, double _u): 
   l(_l), u(_u), is_std(false) {}

const double UniformGenerator::operator () () const
{
   if(is_std) return unit_interval_value();
   else return (u-l)*unit_interval_value() + l;
}

void UniformGenerator::describe(ostream& os) const
{
   os << (boost::format(
	    "Uniform: (%f, %f) @ %d"
	    ) % l % u % this);
}
