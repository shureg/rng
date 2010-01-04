#ifndef RANDOMGENERATOR_CLASS_H_
#define RANDOMGENERATOR_CLASS_H_

#include"rng/uig/UnitIntervalGenerator.class.h"
#include <string>
#include <iosfwd>
#include"xml_serialisation/XmlSerialisableObject.class.h"

using XML_SERIALISATION::XmlSerialisableObject;
using XML_SERIALISATION::XmlField;

extern "C"
{
#include "lua.h"
#include "lualib.h"
}

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

	 static void get_external_uig(const UnitIntervalGenerator*);

	 static lua_State* get_lua_State();

      protected:
	 //! Shared uniform random number generator
	 static const UnitIntervalGenerator* uig();

	 static const UnitIntervalGenerator* set_uig();

	 //! Convenience alias for call to the () operator of RNG::RandomGenerator::uig()
	 const double unit_interval_value() const;

      private:

	 static const UnitIntervalGenerator* uig_holder;
      };
}

#endif /*RANDOMGENERATOR_CLASS_H_*/
