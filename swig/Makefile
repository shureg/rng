space :=
space +=
$(space) :=
$(space) +=
, := ,

include $(PROJECT_LIB_PATH)/lib.config.mk
include $(PROJECT_LIB_PATH)/lib.compile.mk

OUTPUT_PATH := output

PYTHON_PREFIX := $(shell env python -c "import sys; print sys.prefix")
PYTHON_VERSION_XY := $(shell env python -c "import sys; print sys.version" | head -n1 | cut -d' ' -f1 | cut -d'.' -f1-2)

LUA_PREFIX := $(shell which lua | cut -d'/' -f1-3)
LUA_VERSION_XY := $(shell env lua -v 2>&1 | cut -d' ' -f2 | cut -d'.' -f1-2)

MODULE_PATH_python := $(PYTHON_PREFIX)/lib/python$(PYTHON_VERSION_XY)/site-packages
MODULE_PATH_lua := $(LUA_PREFIX)/lib/lua/$(LUA_VERSION_XY)
MODULE_PATH_r := $(HOME)/R/lib

SUFFIX_python = py
SUFFIX_r = R

SWIG_INCLUDE_python = $(PYTHON_PREFIX)/include/python$(PYTHON_VERSION_XY)
SWIG_INCLUDE_r = /usr/share/R/include

SWIG_LIBR_PATH = /usr/lib/R/lib

MODULE := $(PROJECT_NAME)

TARGET_LANGS := python lua

INTERFACE_SOURCES = $(foreach l,$(TARGET_LANGS),$(OUTPUT_PATH)/$(MODULE).$l.swig_wrap.cc)
INTERFACE_DEPS = $(patsubst %.cc,%.swd,$(INTERFACE_SOURCES))

.PHONY: swigclean wrap swiginstall

.INTERMEDIATE: $(INTERFACE_SOURCES)

.DELETE_ON_ERROR: $(INTERFACE_SOURCES)

wrap: $(foreach l,$(TARGET_LANGS),$(OUTPUT_PATH)/$(MODULE).$l.swig_wrap.so)

clean:
	@rm -rfv $(OUTPUT_PATH)

install: INTERFACE_FILES = $(shell find . -maxdepth 1 -type f -name "*.swg")
install: $(foreach l,$(TARGET_LANGS),$l_install)
	@for i in $(INTERFACE_FILES); \
	do \
	   install -Dv $$i $(INSTALLED_HDR_PATH)/$(notdir $$i); \
        done

%_install: INSTALLABLE_SCRIPT = $(if $(SUFFIX_$*),$(shell find $(OUTPUT_PATH) -maxdepth 1 -type f -regex ".*$(MODULE)_$*_swig_wrap\.$(SUFFIX_$*)"))
%_install: INSTALLABLE_LIB = $(shell find $(OUTPUT_PATH) -maxdepth 1 -type f -regex ".*$(MODULE)\.$*\.swig_wrap\.so")

%_install:
	$(if $(INSTALLABLE_SCRIPT),@install -Dv --backup=numbered $(INSTALLABLE_SCRIPT) $(MODULE_PATH_$*)/$(notdir $(INSTALLABLE_SCRIPT)),)
	@install -Dv --backup=numbered $(INSTALLABLE_LIB) $(MODULE_PATH_$*)/$(notdir $(INSTALLABLE_LIB))
	@$(call make_link,$(MODULE_PATH_$*)/$(notdir $(INSTALLABLE_LIB)),$(call get_prefix,$*)$(call get_wrap_lib_name,$(INSTALLABLE_LIB)).so)


-include $(INTERFACE_DEPS)

$(OUTPUT_PATH)/$(MODULE).%.swig_wrap.so: TARGET_LANG = $*
$(OUTPUT_PATH)/$(MODULE).%.swig_wrap.so: DL_PREFIX = $(call get_prefix,$(TARGET_LANG))
$(OUTPUT_PATH)/$(MODULE).%.swig_wrap.so: WRAP_MODULE_NAME = $(call get_wrap_lib_name,$@)
$(OUTPUT_PATH)/$(MODULE).%.swig_wrap.so: WRAP_LIB_SO_NAME = $(DL_PREFIX)$(WRAP_MODULE_NAME).so
$(OUTPUT_PATH)/$(MODULE).%.swig_wrap.so: SWIG_RPATH_FLAG = $(if $(filter-out release,$(PROJECT_CONFIGURATION_TYPE)),$(,)-rpath=$(PROJECT_LIB_PATH),)

$(OUTPUT_PATH)/$(MODULE).%.swig_wrap.so: $(OUTPUT_PATH)/$(MODULE).%.swig_wrap.o
	g++ -shared -Wl,-soname=$(notdir $@)$(SWIG_RPATH_FLAG) -o $@ -L$(PROJECT_LIB_PATH) -llua -l$(LIB_NAME_STEM) $(DL_FLAGS) $< $(DL_FLAGS) -l$(LIB_NAME_STEM) -llua
	@$(call make_link,$(CURDIR)/$@,$(WRAP_LIB_SO_NAME))

$(OUTPUT_PATH)/$(MODULE).%.swig_wrap.cc: $(MODULE).%.swig_wrap.swg
	@mkdir -pv $(OUTPUT_PATH)
	$(call swig_depend,$<,$(OUTPUT_PATH)/$(MODULE).$*.swig_wrap.swd,$@,-$(TARGET_LANG) -I$(PROJECT_INCLUDE_PATH))
	swig -c++ -$(TARGET_LANG) -I$(PROJECT_INCLUDE_PATH) -outdir $(OUTPUT_PATH) $(SWIG_FLAGS) -o $@ $<

#$(MODULE).python.swig_wrap.cc: SWIG_FLAGS += -classic
#$(MODULE).%.swig_wrap.o: LIB_INCLUDE_PATHS += $(SWIG_INCLUDE_$*)

$(OUTPUT_PATH)/$(MODULE).python.swig_wrap.o: LIB_INCLUDE_PATHS += $(SWIG_INCLUDE_python)

$(OUTPUT_PATH)/$(MODULE).r.swig_wrap.so: DL_FLAGS += -L$(SWIG_LIBR_PATH) -lR
$(OUTPUT_PATH)/$(MODULE).r.swig_wrap.o: LIB_INCLUDE_PATHS += $(SWIG_INCLUDE_r)

#%.o: %.cc
#	g++ -c -g -fPIC -o $@ $(INCLUDE_FLAGS) $<


#usage $(call swig_depend,interface_file,dep_file,target_name,flags)
define swig_depend
swig -c++ $4 -MM -MF $2 -MT $3 $1
endef

PREFIXED_LANGS = python
define get_prefix
$(if $(findstring $1,$(PREFIXED_LANGS)),_)
endef

define get_wrap_lib_name
$(subst .,_,$(basename $(notdir $1)))
endef

#usage $(call get_lang,filename,separator)
define get_lang
$(filter-out $(MODULE) swig_wrap swig wrap, $(subst $2,$( ),$1))
endef

#usage $(call make_link,target,linkname)
define make_link
ln -fsv $1 $(join $(dir $1),$2)
endef
