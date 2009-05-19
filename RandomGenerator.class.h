#ifndef RANDOMGENERATOR_CLASS_H_
#define RANDOMGENERATOR_CLASS_H_

#include"rng/UniformGenerator.class.h"

namespace MCS_RNG
{
	//! A prototype of a generic random generator
	/*! Enforces the notion of a uniform random number generator that is shared
		accross all random generators. */
	class RandomGenerator
	{
	protected:
		//! Shared uniform random number generator
		static UniformGenerator* uni_gen;
	public:
		virtual const char* id() = 0;
	};
}

#endif /*RANDOMGENERATOR_CLASS_H_*/
