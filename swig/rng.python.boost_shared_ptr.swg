%include "python/boost_shared_ptr.i"
SWIG_SHARED_PTR(bspTRG_d, RNG::TypedRandomGenerator<double>)

SWIG_SHARED_PTR(bspTRG_ul, RNG::TypedRandomGenerator<unsigned long>)

SWIG_SHARED_PTR_DERIVED(bspUniformGenerator,RNG::TypedRandomGenerator<double>,RNG::UniformGenerator)

SWIG_SHARED_PTR_DERIVED(bspConstGenerator_double,RNG::TypedRandomGenerator<double>,RNG::ConstGenerator<double>)

SWIG_SHARED_PTR_DERIVED(bspICDFG_d,RNG::TypedRandomGenerator<double>,RNG::InverseCDFGenerator<double>)

SWIG_SHARED_PTR_DERIVED(bspICDFG_ul,RNG::TypedRandomGenerator<unsigned long>,RNG::InverseCDFGenerator<unsigned long>)

SWIG_SHARED_PTR_DERIVED(bspNormalGenerator,RNG::InverseCDFGenerator<double>,RNG::NormalGenerator)

SWIG_SHARED_PTR_DERIVED(bspParetoGenerator,RNG::InverseCDFGenerator<double>,RNG::ParetoGenerator)

SWIG_SHARED_PTR_DERIVED(bspLuaDiscreteTableGenerator,RNG::InverseCDFGenerator<double>,RNG::LuaDiscreteTableGenerator)

SWIG_SHARED_PTR_DERIVED(bspURG,RNG::TypedRandomGenerator<double>,RNG::UniformRatioGenerator)

SWIG_SHARED_PTR_DERIVED(bspurTGenerator,RNG::UniformRatioGenerator,RNG::urTGenerator)

SWIG_SHARED_PTR_DERIVED(bspBetaGenerator,RNG::TypedRandomGenerator<double>,RNG::BetaGenerator)

SWIG_SHARED_PTR_DERIVED(bspTriangularGenerator,RNG::InverseCDFGenerator<double>,RNG::TriangularGenerator)

SWIG_SHARED_PTR_DERIVED(bspTODG_ul, RNG::InverseCDFGenerator<unsigned long>, RNG::TabulatedOnDemandGenerator<unsigned long>)

SWIG_SHARED_PTR_DERIVED(bspTODIG_ul, RNG::TabulatedOnDemandGenerator<unsigned long>, RNG::todIntegerGenerator<unsigned long>)

SWIG_SHARED_PTR_DERIVED(bsptodZetaGenerator,RNG::todIntegerGenerator<unsigned long>,RNG::todZetaGenerator)
