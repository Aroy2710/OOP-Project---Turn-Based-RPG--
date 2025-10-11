#include "Action.h"
#Compiler
CXX = g++
#Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra -g

DRMEMORY = C:/Program Files (x86)/Dr. Memory/bin/drmemory.exe
#Executable name 

TESTTARGET = TestRunner

#Source files for testing 
TESTSRCS =  main.cpp Player.cpp  Ranger.cpp Warrior.cpp Mage.cpp

.PHONY: all clean memcheck
#run all tests
TESTALL:
	$(CXX) $(CXXFLAGS) -o $(TESTTARGET) $(TESTSRCS)
	./$(TESTTARGET)

#deleting object files
clean:
	rm -f $(TESTTARGET)

# Memory check target
memcheck:
	$(CXX) $(CXXFLAGS) -o $(TESTTARGET) $(TESTSRCS)
ifeq ($(OS),Windows_NT)
	@echo "Running Dr. Memory (Windows)..."
	"$(DRMEMORY)" -- ./$(TESTTARGET)
else
	@echo "Running Valgrind (Linux/WSL)..."
	valgrind --leak-check=full ./$(TESTTARGET)
endif

