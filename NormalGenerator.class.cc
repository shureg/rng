#include"rng/NormalGenerator.class.h"
#include"rng/Normals.h"
#include<cmath>

using namespace MCS_RNG;

NormalGenerator::NormalGenerator(): mean(0.0), var(1.0), is_std(true) {}

NormalGenerator::NormalGenerator(double _mean, double _var): mean(_mean), var(_var), is_std(false) {}

NormalGenerator::~NormalGenerator() {}

double NormalGenerator::InverseCDF(double u)
{
	double z = GAUSSIAN_NUMERICS::InverseCumulativeNormal(u);

	if(is_std) return z;
	else return z*std::sqrt(var)+mean;
}

const char* NormalGenerator::id(){return "Normal";}
