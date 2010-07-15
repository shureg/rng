// =====================================================================================
// 
//       Filename:  mtwistGenerator.class.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  09/07/10 21:00:49
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#ifndef  MTWISTGENERATOR_CLASS_INC
#define  MTWISTGENERATOR_CLASS_INC

#include "boost/thread.hpp"
#include "rng/mtwist/mtwist.h"
#include "rng/uig/UnitIntervalGenerator.class.h"

namespace RNG
{
   class mtwistGenerator: public UnitIntervalGenerator
   {
   public:

      mtwistGenerator();

      double operator() () const;

   protected:
      
      static mt_prng seeder;

      static boost::mutex seeder_mutex; 


      mutable mt_prng mtwist_gen;
   };
}

#endif   // ----- #ifndef MTWISTGENERATOR_CLASS_INC  -----
