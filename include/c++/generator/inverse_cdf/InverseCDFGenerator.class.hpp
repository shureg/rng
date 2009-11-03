#ifndef INVERSECDFGENERATOR_CLASS_HPP_
#define INVERSECDFGENERATOR_CLASS_HPP_

#include"rng/generator/TypedRandomGenerator.class.hpp"

namespace RNG
{
	//! An inverse CDF random number generator
	/*! Uses the inverse distribution function to transform standard uniform random variates into
		random numbers with the required distribution */
	template<typename T> class InverseCDFGenerator: public TypedRandomGenerator<T>
	{
	protected:
		//! Distribution-specific inverse CDF method
		virtual const T InverseCDF(double) const = 0;
	public:
		const T operator () () const;
	};

	template<typename T> const T InverseCDFGenerator<T>::operator ()() const
	{
		return InverseCDF(this->unit_interval_value());
	}
}

#endif /*INVERSECDFGENERATOR_CLASS_HPP_*/
