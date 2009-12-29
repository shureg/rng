%{
#include "generator/UniformGenerator.class.h"
#include "generator/inverse_cdf/NormalGenerator.class.h"
#include "generator/inverse_cdf/ParetoGenerator.class.h"
#include "generator/uniform_ratio/UniformRatioGenerator.class.h"
#include "generator/uniform_ratio/urTGenerator.class.h"
%}

%include "python/boost_shared_ptr.i"
SWIG_SHARED_PTR(bspTRG_d, RNG::TypedRandomGenerator<double>)

%import "generator/TypedRandomGenerator.class.hpp"
%template(TypedRandomGenerator_double) RNG::TypedRandomGenerator<double>;

%ignore xml_description;

SWIG_SHARED_PTR_DERIVED(bspUniformGenerator,RNG::TypedRandomGenerator<double>,RNG::UniformGenerator)
%include "generator/UniformGenerator.class.h"

SWIG_SHARED_PTR_DERIVED(bspICDFG_d,RNG::TypedRandomGenerator<double>,RNG::InverseCDFGenerator<double>)
%import "generator/inverse_cdf/InverseCDFGenerator.class.hpp"
%template(InverseCDFGenerator_double) RNG::InverseCDFGenerator<double>;

SWIG_SHARED_PTR_DERIVED(bspNormalGenerator,RNG::InverseCDFGenerator<double>,RNG::NormalGenerator)
%include "generator/inverse_cdf/NormalGenerator.class.h"

SWIG_SHARED_PTR_DERIVED(bspParetoGenerator,RNG::InverseCDFGenerator<double>,RNG::ParetoGenerator)
%include "generator/inverse_cdf/ParetoGenerator.class.h"

SWIG_SHARED_PTR_DERIVED(bspURG,RNG::TypedRandomGenerator<double>,RNG::UniformRatioGenerator)
%include "generator/uniform_ratio/UniformRatioGenerator.class.h"

SWIG_SHARED_PTR_DERIVED(bspurTGenerator,RNG::UniformRatioGenerator,RNG::urTGenerator)
%include "generator/uniform_ratio/urTGenerator.class.h"
