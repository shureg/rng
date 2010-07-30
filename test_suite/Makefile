all: mthread

mthread: mthread.o
	g++ -o $@ -lrng $< -llua -ldl

mthread.o: CXXFLAGS += -g -fPIC -O2
