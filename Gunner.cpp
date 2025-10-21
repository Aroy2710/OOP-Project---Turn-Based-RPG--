#include "Gunner.h"

// Default constructor.
// Initializes a Gunner with default Ranger attributes.
Gunner::Gunner() : Ranger() { 
  this->weapon = "Gun"; 
}

// Constructor with a custom name.
// Initializes a Gunner with default Ranger attributes and the given name.
Gunner::Gunner(string name) : Ranger(name) { 
  this->weapon = "Gun"; 
}

// Fully parameterized constructor.
// Useful for testing with explicit stat values.
Gunner::Gunner(string name, string weapon, float attackStat, float defenseStat,
               float healthStat)
    : Ranger(name, weapon, attackStat, defenseStat, healthStat) { 
  this->weapon = "Gun"; 
}

// Executes the Gunner’s special skill.
// Deals damage and increases defense permanently.
void Gunner::useSpecialSkill(Entity* entity) {
  if (!entity) {
    if (gameText) std::cout << name << " tried to attack, but there's no target!\n";
    return;
  }
  if (specialSkillCounter > 0) {
    if (gameText) {
      cout << "The Gunner aims for the enemy's head with their " << weapon << endl;
    }

    float damage = 3 * attackStat;
    entity->takeDamage(damage);

    defenseStat += 30;
    specialSkillCounter -= 1;
  } else if (gameText) {
    cout << "You have used up all your special skill charges." << endl;
  }
}

void Gunner::basicAttack(Entity* entity)
{
  float damage = dexterity;
  if (!entity) {
    if (gameText) std::cout << name << " tried to attack, but there's no target!\n";
    return;
  }
  if (gameText) {
    cout << name << " is now attacking with their " << weapon << endl;
  }
  entity->takeDamage(damage);
  
}


// Destructor.
Gunner::~Gunner() = default;
