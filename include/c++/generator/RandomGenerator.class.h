#ifndef RANDOMGENERATOR_CLASS_H_
#define RANDOMGENERATOR_CLASS_H_

#include"rng/uig/UnitIntervalGenerator.class.h"
#include <string>
#include <iosfwd>
#include"xml_serialisation/XmlSerialisableObject.class.h"

#include "rng/generator/init.h"

using XML_SERIALISATION::XmlSerialisableObject;
using XML_SERIALISATION::XmlField;

namespace RNG
{
      //! A prototype of a generic random generator
      class RandomGenerator: public XmlSerialisableObject
      {
      public:

	 RandomGenerator();

	 virtual ~RandomGenerator() = 0;

      protected:

	 //! Convenience alias for call to the () operator of RNG::uig
	 const double unit_interval_value() const;

      };
}

#endif /*RANDOMGENERATOR_CLASS_H_*/
