// =====================================================================================
// 
//       Filename:  HistogramGenerator.class.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  28/05/09 12:46:12
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#ifndef  _RNG_HISTOGRAMGENERATOR_CLASS_INC
#define  _RNG_HISTOGRAMGENERATOR_CLASS_INC

#include "rng/piecewise/PiecewiseRandomGenerator.class.hpp"
#include "rng/UniformGenerator.class.h"
#include <vector>
#include <string>
#include <utility>

namespace RNG
{
   class HistogramGenerator: public PiecewiseRandomGenerator<double>
   {
   public:

      HistogramGenerator();

      HistogramGenerator(const std::vector<double>&, 
	    const std::vector< std::pair<double,double> >&);

      //! File-based constructor
      HistogramGenerator(const std::string&);

   protected:

     void populate(const std::vector<double>&,
	   const std::vector< std::pair<double,double> >&);
   
   };
}

#endif   // ----- #ifndef _RNG_HISTOGRAMGENERATOR_CLASS_INC  -----
