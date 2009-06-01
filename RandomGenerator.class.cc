#include"RandomGenerator.class.h"
#include"UIG_Dictionary.class.h"
#include<fstream>
#include<string>
#include<iostream>
#include<stdexcept>

using namespace RNG;

RandomGenerator::~RandomGenerator() {}

const UIG_Dictionary& RandomGenerator::uig_dict()
{
   static UIG_Dictionary dummy = UIG_Dictionary();

   return dummy;
}

const std::string& RandomGenerator::uig_name()
{
   std::ifstream ifs("/home/shureg/etc/uig.cfg");

   static std::string dummy;

   if(ifs.good()) getline(ifs,dummy);
   else
      throw std::runtime_error("uig.cfg could not be found!");

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
