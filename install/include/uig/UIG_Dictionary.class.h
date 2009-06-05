// =====================================================================================
// 
//       Filename:  UIG_Dictionary.class.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  19/05/09 14:07:36
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================


#ifndef  _RNG_UIG_DICTIONARY_CLASS_INC
#define  _RNG_UIG_DICTIONARY_CLASS_INC

#include "uig/UnitIntervalGenerator.class.h"
#include "uig/gslPRGenerator.class.h"
#include <string>

namespace RNG
{
   class UIG_Dictionary
   {
   private:

      gslPRGenerator gsl_pr;

   public:

      UnitIntervalGenerator* which(const std::string&) const;
   };
}

#endif   // ----- #ifndef _RNG_UIG_DICTIONARY_CLASS_INC  -----
