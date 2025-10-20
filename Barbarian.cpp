#include "Barbarian.h"

// Default constructor.
// Initializes a Barbarian with default Warrior attributes.
Barbarian::Barbarian() : Warrior() { 
  weapon = "Fist"; 
}

// Constructor with a custom name.
// Initializes a Barbarian with the given name.
Barbarian::Barbarian(string name) : Warrior(name) { 
  weapon = "Fist"; 
}

// Fully parameterized constructor.
// Useful for testing with explicit stat values.
Barbarian::Barbarian(string name, string weapon, float attackStat, float defenseStat,
                     float healthStat)
    : Warrior(name, weapon, attackStat, defenseStat, healthStat) { 
  this->weapon = "Fist"; 
}

void Barbarian::basicAttack(Entity* entity)
{
  float damage = 1.2*strength;
  if (!entity) {
    if (gameText) std::cout << name << " tried to attack, but there's no target!\n";
    return;
  }
  if (gameText) {
    cout << name << " is now attacking with their " << weapon << endl;
  }
  entity->takeDamage(damage);
  
  
}

// Executes the Barbarian’s special skill.
// Deals heavy damage, increases strength, and decreases defense.
void Barbarian::useSpecialSkill(Entity* entity) {
  if (!entity) {
    if (gameText) std::cout << name << " tried to attack, but there's no target!\n";
    return;
  }
  if (specialSkillCounter > 0) {
    if (gameText) {
      cout << "The Barbarian jumps up at the enemy!" << endl;
      cout << "The Barbarian’s strength increases, but defense decreases!" << endl;
    }

    float damage = (2 * strength) + attackStat;
    entity->takeDamage(damage);

    strength += 10;
    defenseStat -= 5;
    specialSkillCounter -= 1;

  } else if (gameText) {
    cout << "You have used up all your special skill charges." << endl;
  }
}

// Destructor.
Barbarian::~Barbarian() = default;
