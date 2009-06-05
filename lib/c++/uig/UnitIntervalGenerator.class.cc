#include"uig/UnitIntervalGenerator.class.h"
#include <stdexcept>

using namespace RNG;

bool UnitIntervalGenerator::endpoint_reachable(int ep)
{
   if(ep==0) return can_be_zero;
   else if(ep==1) return can_be_one;
   else
   {
      throw std::logic_error(
         "Incorrect endpoint specified in MCS_RNG::UnitIntervalGenerator::endpoint_reachable(int)");
   }
}

UnitIntervalGenerator::UnitIntervalGenerator(bool _can_be_zero, bool _can_be_one):
   can_be_zero(_can_be_zero), can_be_one(_can_be_one) {}

UnitIntervalGenerator::~UnitIntervalGenerator() {}
