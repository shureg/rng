#ifndef TYPEDRANDOMGENERATOR_CLASS_HPP_
#define TYPEDRANDOMGENERATOR_CLASS_HPP_

#include"RandomGenerator.class.h"

namespace RNG
{
	//! A generic templated random number generator
	/*! Returns a random value of a specified type */
	template<typename T> class TypedRandomGenerator: public RandomGenerator
	{
	public:
		//! Random number generator method
		virtual const T operator() () const = 0;
	};
}

#endif /*TYPEDRANDOMGENERATOR_CLASS_HPP_*/
