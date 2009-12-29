%{
#include "generator/UniformGenerator.class.h"
#include "generator/inverse_cdf/NormalGenerator.class.h"
#include "generator/inverse_cdf/ParetoGenerator.class.h"
#include "generator/uniform_ratio/UniformRatioGenerator.class.h"
#include "generator/uniform_ratio/urTGenerator.class.h"
%}

%import "generator/TypedRandomGenerator.class.hpp"
%template(TypedRandomGenerator_double) RNG::TypedRandomGenerator<double>;

%ignore xml_description;
%include "generator/UniformGenerator.class.h"

%import "generator/inverse_cdf/InverseCDFGenerator.class.hpp"
%template(InverseCDFGenerator_double) RNG::InverseCDFGenerator<double>;

%include "generator/inverse_cdf/NormalGenerator.class.h"
%include "generator/inverse_cdf/ParetoGenerator.class.h"

%include "generator/uniform_ratio/UniformRatioGenerator.class.h"

%include "generator/uniform_ratio/urTGenerator.class.h"
