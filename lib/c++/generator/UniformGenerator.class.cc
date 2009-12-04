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

#include"rng/generator/UniformGenerator.class.h"
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

XmlField UniformGenerator::xml_description() const
{
   XmlField tmp("Uniform.Random.Generator");
   tmp.add_field("lower_bound",l);
   tmp.add_field("upper_bound",u);

   return tmp;
}
