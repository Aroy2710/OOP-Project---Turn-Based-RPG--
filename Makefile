#include "Action.h"
#Compiler
CXX = g++
#Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra 

#Executable name 

TESTTARGET = TestRunner

#Source files for testing 
TESTSRCS =  main.cpp Player.cpp  Ranger.cpp Warrior.cpp Mage.cpp

.PHONY: all
#run all tests
TESTALL:
	$(CXX) $(CXXFLAGS) -o $(TESTTARGET) $(TESTSRCS)
	./$(TESTTARGET)

# Clean rule
.PHONY: clean 

#deleting object files
clean:
	rm -f $(TESTTARGET)



