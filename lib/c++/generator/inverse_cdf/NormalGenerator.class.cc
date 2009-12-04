#include"rng/generator/inverse_cdf/NormalGenerator.class.h"
#include"rng/math/Normals.h"
#include<cmath>
#include<iostream>
#include"boost/format.hpp"

using namespace RNG;
using namespace std;

NormalGenerator::NormalGenerator(): mean(0.0), var(1.0), is_std(true) {}

NormalGenerator::NormalGenerator(double _mean, double _var): mean(_mean), var(_var), is_std(false) {}

NormalGenerator::~NormalGenerator() {}

const double NormalGenerator::InverseCDF(double u) const
{
	double z = GAUSSIAN_NUMERICS::InverseCumulativeNormal(u);

	if(is_std) return z;
	else return z*std::sqrt(var)+mean;
}

XmlField NormalGenerator::xml_description() const
{
   XmlField tmp("Normal.Random.Generator");

   tmp("generator_type") = "inverse cdf";

   tmp.add_field("mean",mean);
   tmp.add_field("variance",var);

   return tmp;
}
