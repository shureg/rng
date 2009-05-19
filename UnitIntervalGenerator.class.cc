#include"rng/UnitIntervalGenerator.class.h"
#include"core/StringStreamException.class.h"

using namespace MCS_RNG;
using MCS_CORE::StringStreamException;

bool UnitIntervalGenerator::endpoint_reachable(int ep)
{
   if(ep==0) return can_be_zero;
   else if(ep==1) return can_be_one;
   else
   {
      throw new StringStreamException(
         "Incorrect endpoint specified in MCS_RNG::UnitIntervalGenerator::endpoint_reachable(int)");
   }
}

