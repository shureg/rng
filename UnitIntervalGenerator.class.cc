#include"UnitIntervalGenerator.class.h"
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

