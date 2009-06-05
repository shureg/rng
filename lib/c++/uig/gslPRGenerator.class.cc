#include"uig/gslPRGenerator.class.h"
#include<ctime>

using namespace RNG;

gslPRGenerator::gslPRGenerator(): UnitIntervalGenerator(true,false),
   u( gsl_rng_alloc(gsl_rng_mt19937) ) 
{
	gsl_rng_set(u,(unsigned long int) std::time(NULL));
}

gslPRGenerator::gslPRGenerator(const gslPRGenerator& ug):
   UnitIntervalGenerator(true,false),
   u(gsl_rng_clone(ug.u)) {}

gslPRGenerator& gslPRGenerator::operator = (const gslPRGenerator& ug)
{
   gsl_rng_free(u);

   u = gsl_rng_clone(ug.u);

   set_endpoints();

   return *this;
}

gslPRGenerator::~gslPRGenerator()
{
	gsl_rng_free(u);
}

double gslPRGenerator::operator () () const
{
	return gsl_rng_uniform(u);
}

void gslPRGenerator::set_endpoints()
{
	can_be_zero=true;

	can_be_one=false;
}

UnitIntervalGenerator* gslPRGenerator::clone()
{
   gslPRGenerator* tmp = new gslPRGenerator(*this);

   return (UnitIntervalGenerator*) tmp;
}
