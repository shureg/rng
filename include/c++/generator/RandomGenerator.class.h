#ifndef RANDOMGENERATOR_CLASS_H_
#define RANDOMGENERATOR_CLASS_H_

#include"rng/uig/UnitIntervalGenerator.class.h"
#include <string>
#include <iosfwd>
#include"xml_serialisation/XmlSerialisableObject.class.h"

using XML_SERIALISATION::XmlSerialisableObject;
using XML_SERIALISATION::XmlField;

namespace RNG
{
   class UIG_Dictionary;

	//! A prototype of a generic random generator
	/*! Enforces the notion of a uniform random number generator that is shared
		accross all random generators. */
	class RandomGenerator: public XmlSerialisableObject
	{
	public:

	   virtual ~RandomGenerator() = 0;

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

#endif /*RANDOMGENERATOR_CLASS_H_*/
