#include "healthPotion.h"

// Default constructor
// Sets a default name and heal amount for the health potion.
HealthPotion::HealthPotion() {
  itemName = "Health Potion";
  effectValue = 200;
}

// Constructor
// Initializes the health potion with a custom name and heal amount.
HealthPotion::HealthPotion(std::string name, int healAmount) {
  this->itemName = name;
  this->effectValue = healAmount;
}

// Uses the health potion on the player.
// Increases the player's health by the potion's effect value
// and prints a message to the console.
void HealthPotion::use(Player* player) {
  int current = player->getHealth();
  player->setHealth(current + effectValue);

  std::cout << player->getName() << " used " << itemName
            << " and restored " << effectValue << " health!" << std::endl;
}
