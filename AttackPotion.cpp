#include "AttackPotion.h"
#include "Player.h"

// Default constructor
// Sets a default name and attack boost for the attack potion.
AttackPotion::AttackPotion() 
  : Item("Attack Potion", 30)
{}

// Constructor
// Initializes the attack potion with a custom name and attack boost.
AttackPotion::AttackPotion(std::string name, int attackBoost) 
  : Item(name, attackBoost)
{}

// Uses the attack potion on the player.
// Increases the player's attack by the potion's effect value
// and prints a message to the console.
void AttackPotion::use(Player* target) {
  int current = target->getAttackStat();
  target->setAttackStat(current + effectValue);

  if (gameText) {
    std::cout << target->getName() << " used " << itemName << " and gained " << effectValue << " attack!" << std::endl;
  }
}

// Default destructor
AttackPotion::~AttackPotion() = default;
