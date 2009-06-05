// =====================================================================================
// 
//       Filename:  PiecewiseRandomGenerator.class.hpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  28/05/09 12:24:08
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================


#ifndef  _RNG_PIECEWISERANDOMGENERATOR_CLASS_INC
#define  _RNG_PIECEWISERANDOMGENERATOR_CLASS_INC

#include "rng/TypedRandomGenerator.class.hpp"
#include "rng/UniformGenerator.class.h"
#include "boost/ptr_container/ptr_map.hpp"
#include <iostream>
#include "boost/format.hpp"

namespace RNG
{
   template<typename T> class PiecewiseRandomGenerator: public TypedRandomGenerator<T>
   {
   public:

      const T operator () () const;

      void describe(std::ostream&) const;

   protected:

      UniformGenerator U;

      boost::ptr_map< double, TypedRandomGenerator<T> > dist;

   };

   template<typename T> inline const T PiecewiseRandomGenerator<T>::operator() () const
   {
      return (*((this->dist.lower_bound( U() ))->second))();
   }

   template<typename T> inline void PiecewiseRandomGenerator<T>::describe(std::ostream& os) const
   {
      os << "Piecewise Generator" << this << std::endl;
      for(typename boost::ptr_map<double, TypedRandomGenerator<T> >::const_iterator
	    i=dist.begin(); i!=dist.end(); ++i)
	 os << (boost::format ( "[%f] { %s }\n" ) % (i->first) % (i->second) );
   }
}

#endif   // ----- #ifndef _RNG_PIECEWISERANDOMGENERATOR_CLASS_INC  -----
