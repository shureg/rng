// =====================================================================================
// 
//       Filename:  TabulatedOnDemandGenerator.class.hpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  10/08/2010 05:30:20 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#ifndef  TABULATEDONDEMANDGENERATOR_CLASS_INC
#define  TABULATEDONDEMANDGENERATOR_CLASS_INC

#include "rng/generator/inverse_cdf/InverseCDFGenerator.class.hpp"
#include <map>

namespace RNG
{
   template<typename T> class TabulatedOnDemandGenerator: public InverseCDFGenerator<T>
   {
   public:

      TabulatedOnDemandGenerator(const T&);

   protected:

      mutable std::map<double, T> tabulated_inverse_cdf;

      virtual double probability_mass_function(const T&) const = 0;

      virtual T next_discrete_value( const T& ) const = 0;

      T starting_discrete_value;

      const T InverseCDF(double) const;

   private:

      mutable typename std::map<double, T>::const_reverse_iterator last;

   };

   template<typename T> TabulatedOnDemandGenerator<T>::TabulatedOnDemandGenerator(const T& starting_discrete_value):
      starting_discrete_value(starting_discrete_value)
   {}

   template<typename T> const T TabulatedOnDemandGenerator<T>::InverseCDF(double u) const
   {
      if(tabulated_inverse_cdf.empty())
      {
	 tabulated_inverse_cdf.insert( tabulated_inverse_cdf.end(),
	       std::pair<double,T>( probability_mass_function(starting_discrete_value), starting_discrete_value )
	       );
	 last = tabulated_inverse_cdf.rbegin();
      }

      double cdf = last->first;
      T value = last->second;

      typename std::map<double,T>::iterator where;

      if(cdf < u)
      {
	 do
	 {
	    value = next_discrete_value(value);
	    cdf += probability_mass_function(value);
	    where = tabulated_inverse_cdf.insert(tabulated_inverse_cdf.end(), std::pair<double,T>(cdf,value) );
	 }
	 while(cdf < u);

	 last = tabulated_inverse_cdf.rbegin();
      }
      else
      {
	 where = tabulated_inverse_cdf.lower_bound(u);
      }

      return where->second;
   }
}

#endif   // ----- #ifndef TABULATEDONDEMANDGENERATOR_CLASS_INC  -----
