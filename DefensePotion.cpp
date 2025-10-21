#include "DefensePotion.h"
#include "Player.h"

// Default constructor
// Sets a default name and defense boost for the defense potion.
DefensePotion::DefensePotion() 
  : Item("Defense Potion", 20)
{}

// Constructor
// Initializes the defense potion with a custom name and defense boost.
DefensePotion::DefensePotion(std::string name, int defenseBoost) 
  : Item(name, defenseBoost)
{}

// Uses the defense potion on the player.
// Increases the player's defense by the potion's effect value
// and prints a message to the console.
void DefensePotion::use(Player* target) {
  int current = target->getDefenseStat();
  target->setDefenseStat(current + effectValue);

  if (gameText) {
    std::cout << target->getName() << " used " << itemName << " and gained " << effectValue << " defense!" << std::endl;
  }
}

// Default destructor
DefensePotion::~DefensePotion() = default;
