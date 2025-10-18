#include "HealthPotion.h"
#include "Player.h"

// Default constructor
// Sets a default name and heal amount for the health potion.
HealthPotion::HealthPotion() 
  : Item("Health Potion", 200)
{}

// Constructor
// Initializes the health potion with a custom name and heal amount.
HealthPotion::HealthPotion(std::string name, int healAmount) 
  : Item(name, healAmount)
{}

// Uses the health potion on the player.
// Increases the player's health by the potion's effect value
// and prints a message to the console.
void HealthPotion::use(Player* target) {
  int current = target->getHealthStat();
  target->setHealthStat(current + effectValue);

  if (gameText) {
    std::cout << target->getName() << " used " << itemName << " and restored " << effectValue << " health!" << std::endl;
  }
}

// Default destructor
HealthPotion::~HealthPotion() = default;