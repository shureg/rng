// =====================================================================================
// 
//       Filename:  shuffle.hpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  02/03/10 17:49:12
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#ifndef  SHUFFLE_INC
#define  SHUFFLE_INC

#include "rng/generator/UniformIntGenerator.class.h"

#include <algorithm>
#include <iterator>

namespace RNG
{
   template<typename RandomAccessIterator>
      void knuth_shuffle(RandomAccessIterator begin, RandomAccessIterator end)
      {
	 for(unsigned int n = end - begin - 1; n >= 1; --n)
	 {
	    unsigned int k = UniformIntGenerator(0,n+1)();
	    if( k != n )
	       std::iter_swap(begin+k,begin+n);
	 }

      }
}

#endif   // ----- #ifndef SHUFFLE_INC  -----
