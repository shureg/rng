#ifndef TYPEDRANDOMGENERATOR_CLASS_HPP_
#define TYPEDRANDOMGENERATOR_CLASS_HPP_

#include "rng/generator/RandomGenerator.class.h"
#include <iostream>
#include <string>

namespace RNG
{
	//! A generic random number generator
	/*! Returns a random value of a specified type */
	template<typename T> class TypedRandomGenerator: public RandomGenerator
	{
	public:
		//! Random number generator method
		virtual const T operator() () const = 0;

		const T generate() const
		{
		   return (*this)();
		}

		void stream_dump(std::ostream& os, unsigned long N, const std::string sep="\n") const
		{
		   for(unsigned long i=0; i<N-1; ++i)
		      os << (*this)() << sep;
		   os << (*this)();
		}
	};
}

#endif /*TYPEDRANDOMGENERATOR_CLASS_HPP_*/
