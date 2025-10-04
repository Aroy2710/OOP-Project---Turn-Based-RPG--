#include "Action.h"
#Compiler
CXX = g++
#Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra 

#Executable name 

TESTTARGET = playerTestRunner

#Source files
SRCS = playerMain.cpp Player.cpp 

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



