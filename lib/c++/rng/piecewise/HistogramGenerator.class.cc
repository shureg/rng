// =====================================================================================
// 
//       Filename:  HistogramGenerator.class.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  28/05/09 12:56:03
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#include "rng/piecewise/HistogramGenerator.class.h"
#include <stdexcept>
#include "boost/algorithm/string/split.hpp"
#include "boost/algorithm/string/classification.hpp"
#include <fstream>
#include "boost/format.hpp"
#include <iostream>

using namespace RNG;
using namespace std;
using namespace boost::algorithm;

typedef boost::format bf;

HistogramGenerator::HistogramGenerator() {}

HistogramGenerator::HistogramGenerator(const vector<double>& weights,
      const vector< pair<double, double> >& intervals)
{
   if( weights.size() != intervals.size() )
      throw std::logic_error("HistogramGenerator::HistogramGenerator: \
	    sizes of thw weights vector and the intervals vector do not \
	    match");

   populate(weights,intervals);
}

HistogramGenerator::HistogramGenerator(const string& filename)
{
   vector<string> tokenised;
   string line;

   ifstream ifs(filename.c_str());

   vector<double> weights;
   vector< pair<double,double> > intervals;

   if( !ifs.good() )
      throw std::logic_error( (bf(
	       "HistogramGenerator::HistogramGenerator(const string&): \
	       histogram parameter file %s could not be opened")
	    % filename).str()
	    );

   while( ifs.good() )
   {
      getline(ifs,line);

      if( line.size()>0 )
      {
	 split(tokenised,line,is_any_of("\t ,-="));
	 if(tokenised.size()!=3)
	    throw std::logic_error( (bf(
		     "HistogramGenerator::HistogramGenerator(const string&): \
		     file: %s : \n\t\
		     the number of tokens in line %s is not equal to 3")
		  % filename % line).str()
		  );
	 
	 double w = atof(tokenised[0].c_str());
	 double x = atof(tokenised[1].c_str());
	 double y = atof(tokenised[2].c_str());

	 weights.push_back(w);
	 intervals.push_back( pair<double,double>(
		  min(x,y), max(x,y)) );
      }
   }

   populate(weights,intervals);
}

void HistogramGenerator::populate(const vector<double>& weights,
      const vector< pair<double,double> >& intervals)
{
   double cw = 0.;

   for(unsigned int i = 0; i < weights.size(); ++i)
   {
      cw += weights[i];

      dist.insert(cw, 
	    new UniformGenerator(
	       intervals[i].first,intervals[i].second));
   }

   cout << dist.size() << endl;

   for(boost::ptr_map<double, UniformGenerator>::const_iterator
	 j=dist.begin(); j!=dist.end(); ++j)
      cout << j->first << " " << *(j->second) << endl;
}
