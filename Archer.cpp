#include "Archer.h"

// Default constructor.
// Initializes an Archer with default Ranger attributes.
Archer::Archer() : Ranger() { 
  weapon = "Bow"; 
}

// Constructor for Archer with a custom name.
Archer::Archer(string name) : Ranger(name) { 
  weapon = "Bow"; 
}

// Parameterized constructor.
// Useful for testing with explicit stat values.
Archer::Archer(string name, string weapon, float attackStat, float defenseStat,
               float healthStat)
    : Ranger(name, weapon, attackStat, defenseStat, healthStat) { 
  this->weapon = "Bow"; 
}

// Executes the Archer’s special skill.
// Deals damage and increases attack power permanently.
void Archer::headShot(Action* entity) {
  if (gameText) {
    cout << "The Archer aims carefully for the enemy’s head..." << endl;
  }

  float damage = attackStat + dexterity;
  entity->takeDamage(damage);

  attackStat += 10;
  dexterity = 1.5f * attackStat;
}

// Destructor.
Archer::~Archer() = default;
