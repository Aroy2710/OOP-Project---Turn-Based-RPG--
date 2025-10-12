#include "Gunner.h"

// Default constructor.
// Initializes a Gunner with default Ranger attributes.
Gunner::Gunner() : Ranger() { 
  weapon = "Pistol"; 
}

// Constructor for Gunner with a custom name.
Gunner::Gunner(string name) : Ranger(name) { 
  weapon = "Pistol"; 
}

// Parameterized constructor.
// Useful for testing with explicit stat values.
Gunner::Gunner(string name, string weapon, float attackStat, float defenseStat,
               float healthStat)
    : Ranger(name, weapon, attackStat, defenseStat, healthStat) { 
  this->weapon = "Pistol"; 
}

// Executes the Gunner’s special skill.
// Deals high damage and permanently increases defense.
void Gunner::gunShot(Action* entity) {
  if (gameText) {
    cout << "The Gunner aims for the enemy’s head with their " << weapon
         << "..." << endl;
  }

  float damage = 3 * attackStat;
  entity->takeDamage(damage);
  defenseStat += 10;
}

// Destructor.
Gunner::~Gunner() = default;
