#ifndef TYPEDRANDOMGENERATOR_CLASS_HPP_
#define TYPEDRANDOMGENERATOR_CLASS_HPP_

#include"rng/generator/RandomGenerator.class.h"

namespace RNG
{
	//! A generic random number generator
	/*! Returns a random value of a specified type */
	template<typename T> class TypedRandomGenerator: public RandomGenerator
	{
	public:
		//! Random number generator method
		virtual const T operator() () const = 0;
	};
}

#endif /*TYPEDRANDOMGENERATOR_CLASS_HPP_*/
