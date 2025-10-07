#include "Action.h"
#Compiler
CXX = g++
#Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra 

#Executable name 

TESTTARGET = TestRunner

#Source files
SRCS =  main.cpp Player.cpp  Ranger.cpp

.PHONY: all
#run all tests
TESTALL:
	$(CXX) $(CXXFLAGS) -o $(TESTTARGET) $(SRCS)
	./$(TESTTARGET)

# Clean rule
.PHONY: clean 

#deleting object files
clean:
	rm -f $(TESTTARGET)



