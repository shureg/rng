LIB_NAME_STEM ?= rng

LIB_SRC_SUFFIX ?= .cc

LIB_OBJ_SUFFIX ?= .o

LIB_SRC_DEP_SUFFIX ?= .d

LIB_EXT_DEPS ?= gsl gslcblas

LIB_EXT_DEP_PATHS ?= /usr/local/lib

LIB_INCLUDE_PATHS += /usr/local/include/boost-1_39

LIB_WARNINGS = all overloaded-virtual
