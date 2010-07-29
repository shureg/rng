mtwist/mtwist.o: mtwist/mtwist.c
	gcc -c -fPIC -g -O2 -o $@ $<

mtwist/mtwist.c: $(PROJECT_INCLUDE_PATH)/mtwist/mtwist.h

LIB_OBJECTS += mtwist/mtwist.o
