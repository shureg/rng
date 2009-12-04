// =====================================================================================
// 
//       Filename:  urTGenerator.class.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  04/12/09 13:31:25
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#include "rng/generator/uniform_ratio/urTGenerator.class.h"
#include <cmath>

using RNG::urTGenerator;
using namespace CALLBACK_LOG;

urTGenerator::urTGenerator(double _nu)
{
   if(_nu < 1)
      LOG(EXCEPTION, boost::format("Cannot instantiate a t distribution "\
	       "generator with shape parameter %f - must not be less than 1")
	    % _nu );
   nu = _nu;
   
   a_abs = std::sqrt(2*nu)*pow(nu-1,0.25*(nu-1))/pow(nu+1,0.25*(nu+1));
}

double urTGenerator::density(double x) const
{
   return 1./( std::pow( 1. + x*x/nu, 0.5*(nu+1) ) );
}

double urTGenerator::b() const
{
   return 1.;
}

double urTGenerator::a_plus() const
{
   return a_abs;
}

double urTGenerator::a_minus() const
{
   return -a_abs;
}

const bool urTGenerator::accept(double u, double v, double x) const
{
   return ( x*x <= nu*( std::pow( u, -4./(nu+1) ) - 1 ) );
}

const bool urTGenerator::quick_accept(double u, double v, double x) const
{
   return ( x*x <= 5. - 4.*u*std::pow( 1. + 1./nu, 0.25*(nu+1) ) );
}

const bool urTGenerator::quick_reject(double u, double v, double x) const
{
   return ( x*x >= -3. + (4./u)*std::pow( 1. + 1./nu, -0.25*(nu+1) ) );
}

XmlField urTGenerator::xml_description() const
{
   XmlField tmp("T.Random.Generator");
   
   tmp("generator_type") = "uniform ratio";

   tmp.add_field("nu",nu);

   return tmp;
}
