// =====================================================================================
// 
//       Filename:  mthread.cpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  30/07/10 09:16:57
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#include "boost/thread.hpp"
#include "boost/lambda/bind.hpp"
#include "boost/format.hpp"

#include "rng/rng.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

using namespace RNG;

unsigned long run_ctr;

boost::mutex run_ctr_mutex;

void run(ofstream& ofs, unsigned long N_writes, const TypedRandomGenerator<double>& gen)
{
   for(unsigned long i=0; i<N_writes; ++i)
      ofs << gen() << endl;
}

void do_runs(unsigned long N_runs, unsigned long N_writes)
{
   UniformGenerator U;

   string fname = (boost::format("output/rng.%s.out") % (boost::this_thread::get_id()) ).str();

   ofstream ofs(fname.c_str());

   while(run_ctr < N_runs)
   {
      run(ofs,N_writes,U);

      {
	 boost::lock_guard<boost::mutex> run_lock(run_ctr_mutex);
	 ++run_ctr;
      }
   }

   ofs.close();
}

int main(int argc, char** argv)
{
   try
   {
      if(argc < 4) throw "At least 3 arguments must be given on the command line";

      unsigned long N_runs = atol(argv[1]);
      unsigned long N_writes = atol(argv[2]);
      unsigned long N_threads = atol(argv[3]);

      boost::thread_group tg;

      for(unsigned long i = 0; i < N_threads; ++i)
      {
	 using namespace boost::lambda;
	 tg.create_thread( bind(do_runs,N_runs,N_writes) );
      }

      tg.join_all();
   }
   catch(const char* c)
   {
      cerr << "Exception caught: " << c << endl;
      return EXIT_FAILURE;
   }
   catch(const std::string& s)
   {
      cerr << "Exception caught: " << s << endl;
      return EXIT_FAILURE;
   }
   catch(const std::exception& e)
   {
      cerr << "Exception caught: " << e.what() << endl; 
      return EXIT_FAILURE;
   }
   catch(...)
   {
      cerr << "Exception...\n";
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}
