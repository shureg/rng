#include"rng/generator/RandomGenerator.class.h"
#include"rng/uig/UIG_Dictionary.class.h"
#include<fstream>
#include<string>
#include<iostream>
#include<stdexcept>
#include "boost/format.hpp"

#define CONFIG_PREFIX_STR TO_STR(CONFIG_PREFIX)

#define TO_STR(s) TO_STR_HIDDEN(s)

#define TO_STR_HIDDEN(s) #s

using namespace RNG;

RandomGenerator::~RandomGenerator() {}

const UIG_Dictionary& RandomGenerator::uig_dict()
{
   static UIG_Dictionary dummy = UIG_Dictionary();

   return dummy;
}

const std::string& RandomGenerator::uig_name()
{
   std::string us = std::string(CONFIG_PREFIX_STR) + 
      std::string("/etc/rng/uig.cfg");

   std::ifstream ifs(us.c_str());

   static std::string dummy;

   if(ifs.good()) getline(ifs,dummy);
   else
      throw std::runtime_error(
	    (boost::format(
	       "uig.cfg could not be opened (looking for %s)")
	    % us).str().c_str());

   ifs.close();

   return dummy;
}

const UnitIntervalGenerator* RandomGenerator::uig()
{
   static UnitIntervalGenerator* dummy = RandomGenerator::uig_dict().
      which(RandomGenerator::uig_name())->clone();

   return dummy;
}

const double RandomGenerator::unit_interval_value() const
{
  return (*RandomGenerator::uig())(); 
}
