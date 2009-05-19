#include"rng/gslPRGenerator.class.h"
#include<ctime>

using namespace MCS_RNG;

gslPRGenerator::gslPRGenerator()
{
	u = gsl_rng_alloc(gsl_rng_mt19937);

	gsl_rng_set(u,(unsigned long int) std::time(NULL));
}

gslPRGenerator::gslPRGenerator(gsl_rng_type* T)
{
	u = gsl_rng_alloc(T);

	gsl_rng_set(u,(unsigned long int) std::time(NULL));
}

gslPRGenerator::gslPRGenerator(const gslPRGenerator& ug)
{
	u = gsl_rng_clone(ug.u);
}

gslPRGenerator::~gslPRGenerator()
{
	gsl_rng_free(u);
}

double gslPRGenerator::operator () ()
{
	return gsl_rng_uniform(u);
}

