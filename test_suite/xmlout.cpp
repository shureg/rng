// =====================================================================================
// 
//       Filename:  xmlout.cpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  08/08/10 19:39:21
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#include "rng/rng.hpp"
#include <iostream>

using namespace std;
using namespace RNG;

int main(int argc, char** argv)
{
   UniformGenerator U;

   cout << U() << endl;

   cout << U.xml_description() << endl;

   TriangularGenerator T(0,1,0.5);

   cout << T() << endl;

   cout << T.xml_description() << endl;
}
