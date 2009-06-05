INCLUDE_DIRS = $(BOOST_INCLUDE_DIR) $(INSTALLED_HDR_PATH)

INCLUDE_FLAGS = $(foreach i,$(INCLUDE_DIRS),-I$i)

all: test_d

-include test.d

test_d: test.o
	g++ $(RPATH_FLAG) -o $@ -lrng -L$(INSTALLED_LIB_PATH) $<

clean:
	@rm -rf test_d
	@rm -rf test_s

%: %.o

%.o: %.cxx
	$(call make_depend,$<,$@,$*.d,$(INCLUDE_FLAGS))
	g++ -g -c -Wall -fPIC $(INCLUDE_FLAGS) -o $@ $<

#A script ot generate dependency files for c/c++ sources
#usage $(call make_depend,src_file,obj_file,dep_file,flags)
define make_depend
   g++ -MM -MF $3 -MP -MT $2 $4 $1
endef
