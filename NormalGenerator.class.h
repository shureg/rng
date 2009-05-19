#ifndef NORMALGENERATOR_CLASS_H_
#define NORMALGENERATOR_CLASS_H_

#include"rng/InverseCDFGenerator.class.hpp"

namespace MCS_RNG
{
	class NormalGenerator: public InverseCDFGenerator<double>
	{
	protected:
		//! Location parameter (mean)
		double mean;

		//! Scale parameter (variance)
		double var;

		//! Standard Normal flag
		bool is_std;

		double InverseCDF(double);

	public:
		//! Default constructor
		/* Provides a standard Normal distribution */
		NormalGenerator();

		//! Parametrised constructor
		NormalGenerator(double,double);

		const char* id();

		//! Destructor
		virtual ~NormalGenerator();
	};
}

#endif /*NORMALGENERATOR_CLASS_H_*/
