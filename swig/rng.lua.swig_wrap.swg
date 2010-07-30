%module "rng_lua_swig_wrap"
%{
#include "rng/uig/UnitIntervalGenerator.class.h"
#include "rng/uig/gslPRGenerator.class.h"
#include "rng/generator/RandomGenerator.class.h"
#include "rng/uig/mtwistGenerator.class.h"
#include "rng/generator/init.h"
%}

%ignore endpoint_reachable;
%include "rng/uig/UnitIntervalGenerator.class.h"

namespace RNG
{
   void get_external_uig(UnitIntervalGenerator*);

   class gslPRGenerator: public UnitIntervalGenerator
   {
   public:

      gslPRGenerator();

      double operator() () const;
   };

   class mtwistGenerator: public UnitIntervalGenerator
   {
   public:

      mtwistGenerator();

      double operator() () const;
   };
}

%include "rng/generator/RandomGenerator.class.h"

%include "rng.headers.swg"
%include "rng.lua.interface.swg"
