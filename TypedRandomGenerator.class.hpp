#ifndef TYPEDRANDOMGENERATOR_CLASS_HPP_
#define TYPEDRANDOMGENERATOR_CLASS_HPP_

#include"rng/RandomGenerator.class.h"

namespace MCS_RNG
{
	//! A generic templated random number generator
	/*! Returns a random value of a specified type */
	template<typename T> class TypedRandomGenerator: public RandomGenerator
	{
	public:
		//! Random number generator method
		virtual T operator() () = 0;
	};
}

#endif /*TYPEDRANDOMGENERATOR_CLASS_HPP_*/
