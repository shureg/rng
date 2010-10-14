%ignore xml_description;

%import "generator/TypedRandomGenerator.class.hpp"
%template(TypedRandomGenerator_double) RNG::TypedRandomGenerator<double>;

%import "generator/TypedRandomGenerator.class.hpp"
%template(TypedRandomGenerator_ul) RNG::TypedRandomGenerator<unsigned long>;

%include "generator/UniformGenerator.class.h"

%import "generator/inverse_cdf/InverseCDFGenerator.class.hpp"
%template(InverseCDFGenerator_double) RNG::InverseCDFGenerator<double>;

%import "generator/inverse_cdf/InverseCDFGenerator.class.hpp"
%template(InverseCDFGenerator_ul) RNG::InverseCDFGenerator<unsigned long>;

%import "generator/ConstGenerator.class.hpp"
%template(ConstGenerator_double) RNG::ConstGenerator<double>;

%include "generator/inverse_cdf/NormalGenerator.class.h"

%include "generator/inverse_cdf/ParetoGenerator.class.h"

%include "generator/uniform_ratio/UniformRatioGenerator.class.h"

%include "generator/uniform_ratio/urTGenerator.class.h"

%include "generator/BetaGenerator.class.h"

%include "generator/inverse_cdf/TriangularGenerator.class.h"

%import "generator/inverse_cdf/TabulatedOnDemandGenerator.class.hpp"
%template(TabulatedOnDemand_ul) RNG::TabulatedOnDemandGenerator<unsigned long>;

%import "generator/inverse_cdf/todIntegerGenerator.class.hpp"
%template(toIntegerGenerator_ul) RNG::todIntegerGenerator<unsigned long>;

%include "generator/inverse_cdf/todZetaGenerator.class.h"
