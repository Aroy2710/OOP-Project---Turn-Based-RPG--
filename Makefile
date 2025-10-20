
#Compiler
CXX = g++
#Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra -g

DRMEMORY = C:/Program Files (x86)/Dr. Memory/bin/drmemory.exe
#Executable names


TARGET = main

#Source files for testing 
SRCS =  main.cpp Player.cpp Inventory.cpp Item.cpp HealthPotion.cpp Ranger.cpp Warrior.cpp Mage.cpp Archer.cpp Gunner.cpp Wizard.cpp Warlock.cpp Swordsman.cpp Barbarian.cpp Enemy.cpp Orc.cpp Human.cpp Goblin.cpp BattleManager.cpp GameManager.cpp

.PHONY: all clean memcheck TESTALL

# default: compile everything and run main
all:
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)	
	./$(TARGET)

#run all tests
TESTALL:
	$(CXX) $(CXXFLAGS) -o $(TESTTARGET) $(SRCS)
	./$(TARGET)

#deleting object files
clean:
	rm -f $(TESTTARGET) $(TARGET)


# Memory check target
memcheck:
	$(CXX) $(CXXFLAGS) -o $(TESTTARGET) $(SRCS)
ifeq ($(OS),Windows_NT)
	@echo "Running Dr. Memory (Windows)..."
	"$(DRMEMORY)" -- ./$(TESTTARGET)
else
	@echo "Running Valgrind (Linux/WSL)..."
	valgrind --leak-check=full ./$(TESTTARGET)
endif

