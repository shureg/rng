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

#include "UniformGenerator.class.h"
#include "NormalGenerator.class.h"
#include "HistogramGenerator.class.h"

using namespace std;
using namespace RNG;
 
int main ( int argc, char** argv )
{
   try
   {

      UniformGenerator U(-0.5,0.5);

      NormalGenerator Z;

      for(int i=0; i<10; ++i)
      {
	 cout << U() << '\t' << Z() << endl;
      }

      HistogramGenerator H("hist.cfg");

      ofstream ofs("hist.tst");

      for(int j =0; j<10000; ++j) ofs << H() << endl;

      ofs.close();

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
