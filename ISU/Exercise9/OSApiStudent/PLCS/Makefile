# Quick and dirty (does not handle changes in h-file)
SRCS=main.cpp Car.cpp EntryGuard.cpp ExitGuard.cpp
OBJS=$(SRCS:.cpp=.o)
BASEPATH=..

# Added ability to choose TARGET - Defaults to host
ifndef TARGET
TARGET=host
endif

# Sets compiler to g++ if TARGET is host
ifeq (${TARGET},host)
#echo "Host"
CXX=g++
endif

# Sets compiler to arm-rpizw-g++ if TARGET is host
ifeq (${TARGET},target)
#echo "Target"
CXX=arm-rpizw-g++
endif

# Determine whether this is a debug build or not
ifdef DEBUG
CXXFLAGS=-ggdb -O0
# Updated path to use TARGET's path
LIBPATH=$(BASEPATH)/lib/$(TARGET)/debug 
else
CXXFLAGS=-O2
# Updated path to use TARGET's path
LIBPATH=$(BASEPATH)/lib/$(TARGET)/release
endif

# Setup the CFLAGS to ensure that the relevant warnings, includes and defines.
CXXFLAGS+=-Wall -D_REENTRANT -DOS_LINUX -I$(BASEPATH)/inc

#%.o : %cpp
#	g++ $(CXXFLAGS) -c -o $@ $^
# Then again, note how the flags are NOT part of the linking process
main: $(OBJS)
	$(CXX) -o main $(OBJS)  -L$(LIBPATH) -lOSApi -lrt -lpthread

all: main

clean:$(OBJS)
	rm -f *.o main

