LIB_NAME_STEM ?= $(PROJECT_NAME)

LIB_SRC_SUFFIX ?= .cc

LIB_OBJ_SUFFIX ?= .o

LIB_SRC_DEP_SUFFIX ?= .d

LIB_EXT_DEPS ?= boost_thread gsl gslcblas xml_serialisation callback_log lua dl

#LIB_EXT_DEP_PATHS ?= /usr/local/lib

#BOOST_INCLUDE_PATH ?= /usr/local/include/boost-1_39

#LIB_INCLUDE_PATHS += $(BOOST_INCLUDE_PATH)

LIB_WARNINGS = all overloaded-virtual

LIB_CONFIG_INCLUDED +=
