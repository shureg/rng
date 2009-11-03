#ifndef GSLPRGENERATOR_CLASS_H_
#define GSLPRGENERATOR_CLASS_H_

#include<gsl/gsl_rng.h>
#include"rng/uig/UnitIntervalGenerator.class.h"

namespace RNG
{
	//! A pseudo-random model of a unit interval generator that utilises the GSL library
	/*! Generates uniform random numbers on the unit interval, using the GNU Scientific Library routines*/
	class gslPRGenerator: public UnitIntervalGenerator
	{
	private:

	   //! Internal convenience routine to set the reachability of endpoints 
	   void set_endpoints();

	protected:
		//! The type of the uniform random number generator
		gsl_rng* u;
	public:
		//! Default constructor
		/*! Uses the standard Mersenne twister (mt19937) algorithm and a timer seed*/
		gslPRGenerator();

		//! Copy constructor
		gslPRGenerator(const gslPRGenerator&);

		//! Assignment operator
		gslPRGenerator& operator = (const gslPRGenerator&);

		//! Destructor
		virtual ~gslPRGenerator();

		//! The generator method
		/*! Returns a pseudo-random double precision number on a unit interval*/
		double operator() () const ;

		UnitIntervalGenerator* clone();
	};
}

#endif //! GSLPRGENERATOR_CLASS_H_
