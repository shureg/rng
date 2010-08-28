all: mthread xmlout

mthread: mthread.o
	g++ -o $@ -lrng $< -llua -ldl

xmlout: xmlout.o
	g++ -o $@ -lrng $< -llua -ldl

%.o: CXXFLAGS += -g -fPIC -O2
