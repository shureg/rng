// =====================================================================================
// 
//       Filename:  UniformIntGenerator.class.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  02/03/10 17:32:09
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#include "rng/generator/UniformIntGenerator.class.h"
#include <utility>

using namespace RNG;

typedef std::pair<double, int> lb_type;

UniformIntGenerator::UniformIntGenerator(int begin, int end):
   begin(begin), end(end)
{
   double du = 1./(1.*(end-begin));
   double ul = du;

   for(int i = begin; i < end -1; ++i)
      lower_bounds.insert( lower_bounds.end(), lb_type(ul+=du,i) );

   lower_bounds.insert( lower_bounds.end(), lb_type(1.,end-1));
}

const int UniformIntGenerator::operator () () const
{
   return (lower_bounds.lower_bound( U() ))->second;
}

XmlField UniformIntGenerator::xml_description() const
{
   XmlField tmp("Uniform.Int.Generator");

   tmp("lower_bound") = begin;

   tmp("upper_bound") = end;

   tmp("actual_upper_bound") = end-1;

   return tmp;
}
