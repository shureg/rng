// =====================================================================================
// 
//       Filename:  mtwistGenerator.class.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  09/07/10 21:24:50
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#include "rng/uig/mtwistGenerator.class.h"

using RNG::mtwistGenerator;

mt_prng mtwistGenerator::seeder;

boost::mutex mtwistGenerator::seeder_mutex;

mtwistGenerator::mtwistGenerator(): RNG::UnitIntervalGenerator(true,false)
{
   {
      boost::lock_guard<boost::mutex> seeder_lock(mtwistGenerator::seeder_mutex);
      mtwist_gen.seed32( mtwistGenerator::seeder.lrand() );
   }
}

double mtwistGenerator::operator () () const
{
   return mtwist_gen.drand();
}
