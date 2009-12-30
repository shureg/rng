%include "python/boost_shared_ptr.i"
SWIG_SHARED_PTR(bspTRG_d, RNG::TypedRandomGenerator<double>)

SWIG_SHARED_PTR_DERIVED(bspUniformGenerator,RNG::TypedRandomGenerator<double>,RNG::UniformGenerator)

SWIG_SHARED_PTR_DERIVED(bspICDFG_d,RNG::TypedRandomGenerator<double>,RNG::InverseCDFGenerator<double>)

SWIG_SHARED_PTR_DERIVED(bspNormalGenerator,RNG::InverseCDFGenerator<double>,RNG::NormalGenerator)

SWIG_SHARED_PTR_DERIVED(bspParetoGenerator,RNG::InverseCDFGenerator<double>,RNG::ParetoGenerator)

SWIG_SHARED_PTR_DERIVED(bspURG,RNG::TypedRandomGenerator<double>,RNG::UniformRatioGenerator)

SWIG_SHARED_PTR_DERIVED(bspurTGenerator,RNG::UniformRatioGenerator,RNG::urTGenerator)
