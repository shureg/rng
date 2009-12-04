// =====================================================================================
// 
//       Filename:  UniformRatioGenerator.class.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  04/12/09 13:09:41
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#include "rng/generator/uniform_ratio/UniformRatioGenerator.class.h"

using RNG::UniformRatioGenerator;

const double UniformRatioGenerator::operator() () const
{
   bool stop = false;

   double u,v,x;
   double ap = a_plus();
   double am = a_minus();

   while(!stop)
   {
      u = unit_interval_value()*b();
      v = unit_interval_value()*( ap - am ) + am;
      x = v/u;
      if( quick_accept(u,v,x) )
	 stop = true;
      else
	 if( !quick_reject(u,v,x) )
	    stop = accept(u,v,x);
   }

   return x;
}
