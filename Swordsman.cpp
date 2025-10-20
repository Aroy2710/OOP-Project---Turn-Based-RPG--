#include "Swordsman.h"

// Default constructor.
// Initializes a Swordsman with default Warrior attributes.
Swordsman::Swordsman() : Warrior() { 
  weapon = "Sword"; 
}

// Constructor with a custom name.
// Initializes a Swordsman with the given name.
Swordsman::Swordsman(string name) : Warrior(name) { 
  weapon = "Sword"; 
}

// Fully parameterized constructor.
// Useful for testing with explicit stat values.
Swordsman::Swordsman(string name, string weapon, float attackStat, float defenseStat,
                     float healthStat)
    : Warrior(name, weapon, attackStat, defenseStat, healthStat) { 
  this->weapon = "Sword"; 
}

// Executes the Swordsman’s special skill.
// Deals heavy damage, increases strength, and decreases HP.
void Swordsman::useSpecialSkill(Entity* entity) {
  if (!entity) {
    if (gameText) std::cout << name << " tried to attack, but there's no target!\n";
    return;
  }
  if (specialSkillCounter > 0) {
    if (gameText) {
      cout << "The Swordsman charges at the enemy with their sword!" << endl;
      cout << "The Swordsman's HP decreases in exchange for greater strength!" << endl;
    }

    float damage = (5 * strength) + attackStat;
    entity->takeDamage(damage);

    strength += 10;
    healthStat -= 30;
    specialSkillCounter -= 1;

  } else if (gameText) {
    cout << "You have used up all your special skill charges." << endl;
  }
}

// Destructor.
Swordsman::~Swordsman() = default;
