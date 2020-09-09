CXX := g++
CXXFLAGS := 
CFLAGS := 

hello: hello.o
	$(CXX) hello.o -o $@
	echo Hello $(CFLAGS) $(CXXFLAGS)

hello.o: hello.cpp
	$(CXX) -c $<


.PHONY: clean
clean:
	rm *.o hello
