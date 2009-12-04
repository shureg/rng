// =====================================================================================
// 
//       Filename:  test.cxx
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  19/05/09 15:56:57
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================
#include<iostream>
#include<fstream>
#include<stdexcept>
#include<string>

#include "rng/generator/UniformGenerator.class.h"
#include "rng/generator/inverse_cdf/NormalGenerator.class.h"
#include "rng/generator/piecewise/HistogramGenerator.class.h"
#include "rng/generator/uniform_ratio/urTGenerator.class.h"

using namespace std;
using namespace RNG;
 
int main ( int argc, char** argv )
{
   try
   {

      UniformGenerator U(-0.5,0.5);

      NormalGenerator Z;

      HistogramGenerator H("hist.cfg");

      urTGenerator T(5);

      ofstream ofs("norm.tst");

      ofs << "z\n";

      Z.stream_dump(ofs,10000);

      ofs.close();

      ofs.open("t.tst");

      ofs << "t\n";

      T.stream_dump(ofs,10000);

      cout << U << Z << H << T;

      return EXIT_SUCCESS;
   }
   catch(const std::exception& e)
   {
      string s = e.what();

      cerr << "Exception caught: " << s << endl;

      return EXIT_FAILURE;
   }
   catch(...)
   {
      cerr << "Unspecified exception caught" << endl;
   }
}				// ----------  end of function main  ----------
