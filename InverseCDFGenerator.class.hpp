#ifndef INVERSECDFGENERATOR_CLASS_HPP_
#define INVERSECDFGENERATOR_CLASS_HPP_

#include"rng/TypedRandomGenerator.class.hpp"

namespace MCS_RNG
{
	//! An inverse CDF random number generator
	/*! Uses the inverse distribution function to transform standard uniform random variates into
		random numbers with the required distribution */
	template<typename T> class InverseCDFGenerator: public TypedRandomGenerator<T>
	{
	protected:
		//! Distribution-specific inverse CDF method
		virtual T InverseCDF(double) = 0;
	public:
		T operator () ();
	};

	template<typename T> T InverseCDFGenerator<T>::operator ()()
	{
		return InverseCDF((*RandomGenerator::uni_gen)());
	}
}

#endif /*INVERSECDFGENERATOR_CLASS_HPP_*/
