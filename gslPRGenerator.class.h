#ifndef UNIFORMGENERATOR_CLASS_H_
#define UNIFORMGENERATOR_CLASS_H_

#include<gsl/gsl_rng.h>

namespace MCS_RNG
{
	//! A pseudo-random model of a unit interval generator that utilises the GSL library
	/*! Generates uniform random numbers on the unit interval, using the GNU Scientific Library routines*/
	class UniformGenerator
	{
	protected:
		//! The type of the uniform random number generator
		gsl_rng* u;
	public:
		//! Default constructor
		/*! Uses the standard Mersenne twister (mt19937) algorithm and a timer seed*/
		UniformGenerator();

		//! Type-specific constructor
		/*! Allows the user to specify the type of the uniform random number generator (as supplied
		by the GNU Scientific Library) and uses a timer seed*/
		UniformGenerator(gsl_rng_type*);

		//! Copy constructor
		UniformGenerator(const UniformGenerator&);

		//! Destructor
		virtual ~UniformGenerator();

		//! The generator method
		/*! Returns a pseudo-random double precision number on a unit interval*/
		double operator()();
	};
}

#endif /*UNIFORMGENERATOR_CLASS_H_*/
