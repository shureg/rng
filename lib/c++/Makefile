all: lib

-include lib.config.mk

DY_LIB_NAME = lib$(LIB_NAME_STEM).so
ST_LIB_NAME = lib$(LIB_NAME_STEM).a

lib: $(DY_LIB_NAME) $(ST_LIB_NAME)

LIB_DEP_FLAGS = $(foreach l,$(LIB_EXT_DEPS),-l$l)

LIB_DEP_PATH_FLAGS = $(foreach L,$(LIB_EXT_DEP_PATHS),-L$L)

LIB_DEFINES += $(PROJECT_DEFINES)

LIB_DEFINE_FLAGS =$(foreach D,$(LIB_DEFINES),-D$D=$($D))

ifeq "$(MAKECMDGOALS)" "install"
   ifndef INSTALL_PREFIX
      $(error INSTALL_PREFIX value must be set for installation to proceed)
   endif
endif

include lib.compile.mk

-include lib.custom.mk

$(DY_LIB_NAME): $(LIB_OBJECTS)
	g++ -shared -Wl,-soname,$@ -o $@ $(LIB_DEP_FLAGS) $(LIB_DEP_PATH_FLAGS) $^

$(ST_LIB_NAME): $(LIB_OBJECTS)
	ar -rv $@ $^

export LIB_NAME_STEM
PROJECT_LIB_PATH := $(CURDIR)
export PROJECT_LIB_PATH

wrap: lib
	$(MAKE) --directory=$(PROJECT_WRAP_PATH) --file=Makefile wrap

clean:
	@rm -rfv $(DY_LIB_NAME)
	@rm -rfv $(ST_LIB_NAME)
	@find -name "*$(LIB_OBJ_SUFFIX)" -type f -exec rm -rfv '{}' \;
	$(MAKE) --directory=$(PROJECT_WRAP_PATH) clean

.PHONY: install
install:
	@install -Dv $(DY_LIB_NAME) $(INSTALL_PREFIX)/lib/$(DY_LIB_NAME)
	@install -Dv $(ST_LIB_NAME) $(INSTALL_PREFIX)/lib/$(ST_LIB_NAME)
	$(MAKE) --directory=$(PROJECT_WRAP_PATH) install
