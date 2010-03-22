// =====================================================================================
// 
//       Filename:  BetaGenerator.class.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  22/03/10 13:31:32
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#include "rng/generator/BetaGenerator.class.h"
#include <cmath>
#include <algorithm>

using RNG::BetaGenerator;

using std::min;

const double BetaGenerator::log_4 = log(4.);

BetaGenerator::BetaGenerator(double a, double b):
   a(a), b(b),
   s(a+b),
   lambda( ( min(a,b) <= 1 ) ? ( min(a,b) ) : ( sqrt( (2*a*b - s)/(s-2) ) ) ),
   u(a+lambda)
{}

const double BetaGenerator::operator() () const
{
   do
   {
      U1 = UG();
      U2 = UG();
      V = (1./lambda)*log(U1/(1-U1));
      Y = a*exp(V);
   }while( s*log(s/(b+Y)) + u*V - BetaGenerator::log_4 < log(U1*U1*U2) );

   return Y/(b+Y);
}

XmlField BetaGenerator::xml_description() const
{
   XmlField tmp("Beta.Random.Generator");

   tmp("a") = a;
   tmp("b") = b;

   return tmp;
}
