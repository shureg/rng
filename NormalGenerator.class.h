#ifndef NORMALGENERATOR_CLASS_H_
#define NORMALGENERATOR_CLASS_H_

#include"InverseCDFGenerator.class.hpp"

namespace RNG
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

		const double InverseCDF(double) const;

	public:
		//! Default constructor
		/* Provides a standard Normal distribution */
		NormalGenerator();

		//! Parametrised constructor
		NormalGenerator(double,double);

		//! Destructor
		~NormalGenerator();

		void describe(std::ostream& os) const;
	};
}

#endif /*NORMALGENERATOR_CLASS_H_*/
