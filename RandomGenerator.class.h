#ifndef RANDOMGENERATOR_CLASS_H_
#define RANDOMGENERATOR_CLASS_H_

#include"UnitIntervalGenerator.class.h"
#include <string>
#include <iosfwd>

namespace RNG
{
   class UIG_Dictionary;

	//! A prototype of a generic random generator
	/*! Enforces the notion of a uniform random number generator that is shared
		accross all random generators. */
	class RandomGenerator
	{
	public:

	   virtual ~RandomGenerator() = 0;

	   virtual void describe(std::ostream&) const = 0;

	protected:
		//! Shared uniform random number generator
		static const UnitIntervalGenerator* uig();

		//! Convenience alias for call to the () operator of RNG::RandomGenerator::uig()
		const double unit_interval_value() const;
	
	private:
		static const UIG_Dictionary& uig_dict();

		static const std::string& uig_name();
	};
}

inline std::ostream& operator << (std::ostream& os, 
      const RNG::RandomGenerator& rg)
{
   rg.describe(os);

   return os;
}

#endif /*RANDOMGENERATOR_CLASS_H_*/
