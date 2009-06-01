LIB_OBJECTS = $(patsubst %.cc, %.o, $(shell find . -name "*.cc"))

BOOST_INCLUDE ?= /usr/local/include/boost-1_39

all: lib test

test: test_d test_s

test_s: test.o librng.a
	g++ -o $@ -lgsl -lgslcblas $+

test_d: test.o
	g++ -o $@ -lrng -L. $<

lib: librng.so librng.a

clean:
	@rm -rfv *.o
	@rm -rfv *.a
	@rm -rfv *.so

librng.so: $(LIB_OBJECTS)
	g++ -shared -Wl,-soname,$@ -o $@ -lgsl -lgslcblas $+

librng.a: $(LIB_OBJECTS)
	ar -rv $@ $+

%: %.o

%.o: %.cc
	g++ -g -c -Wall -fPIC -I$(BOOST_INCLUDE) -o $@ $<

%.o: %.cxx
	g++ -g -c -Wall -fPIC -I$(BOOST_INCLUDE) -o $@ $<
