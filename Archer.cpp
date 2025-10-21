#include "Archer.h"

// Default constructor.
// Initializes an Archer with default Ranger attributes.
Archer::Archer() : Ranger() { 
  this->weapon = "Bow"; 
}

// Constructor for Archer with a custom name.
Archer::Archer(string name) : Ranger(name) { 
  this->weapon = "Bow"; 
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
void Archer::useSpecialSkill(Entity* entity) {
  if (!entity) {
    if (gameText) std::cout << name << " tried to attack, but there's no target!\n";
    return;
  }
  if (specialSkillCounter > 0) {
    if (gameText) {
      cout << "The Archer aims carefully for the enemy’s head..." << endl;
      cout << "The Archer's attack stat and therefore dexterity has increased!" << endl;
    }

    float damage = 1.5*(attackStat + dexterity);
    entity->takeDamage(damage);

    attackStat += 20;
    dexterity = 1.5f * attackStat;
    specialSkillCounter -= 1;
  } else if (gameText) {
    cout << "You have used up all your special skill charges." << endl;
  }
}

void Archer::basicAttack(Entity* entity)
{
  float damage = 1.2*dexterity;
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
Archer::~Archer() = default;
