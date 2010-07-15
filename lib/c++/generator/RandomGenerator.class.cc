#include"rng/generator/RandomGenerator.class.h"
#include"rng/uig/UIG_Dictionary.class.h"
#include<fstream>
#include<string>
#include<iostream>
#include<stdexcept>
#include "boost/format.hpp"

#include "callback_log/LOG.h"

using namespace CALLBACK_LOG;

using namespace RNG;

using namespace std;

RandomGenerator::RandomGenerator()
{
   if( RNG::uig.get() == 0)
      init();
}

RandomGenerator::~RandomGenerator() {}

const double RandomGenerator::unit_interval_value() const
{
  return (*RNG::uig)(); 
}
