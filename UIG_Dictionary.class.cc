// =====================================================================================
// 
//       Filename:  UIG_Dictionary.class.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  19/05/09 14:13:34
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#include "UIG_Dictionary.class.h"
#include <stdexcept>
#include <string>
#include <iostream>

using namespace RNG;

UnitIntervalGenerator* UIG_Dictionary::which(const std::string& uig_name) const
{
   if(uig_name=="gslPRGenerator")
   {
      return (UnitIntervalGenerator*) &gsl_pr;
   }
   else
   {
      throw std::logic_error(uig_name);
   }
}
