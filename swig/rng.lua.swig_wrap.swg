%module "rng_lua_swig_wrap"
%{
#include "rng/uig/UnitIntervalGenerator.class.h"
#include "rng/uig/gslPRGenerator.class.h"
#include "rng/generator/RandomGenerator.class.h"
%}

%ignore endpoint_reachable;
%include "rng/uig/UnitIntervalGenerator.class.h"

namespace RNG
{
   class gslPRGenerator: public UnitIntervalGenerator
   {
   public:

      gslPRGenerator();

      double operator() () const;
   };
}

%include "rng/generator/RandomGenerator.class.h"
