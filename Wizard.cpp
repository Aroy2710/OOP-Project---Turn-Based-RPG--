#include "Wizard.h"

// Default constructor.
// Initializes a Wizard with base Mage attributes.
Wizard::Wizard() : Mage() {
  this->weapon = "Staff";
}

// Constructor with a name.
// Initializes a Wizard with base Mage attributes and the given name.
Wizard::Wizard(string name) : Mage(name) {
  this->weapon = "Staff";
}

// Fully parameterized constructor.
// Useful for testing with explicit stat values.
Wizard::Wizard(string name, string weapon, float attackStat, float defenseStat,
               float healthStat)
    : Mage(name, weapon, attackStat, defenseStat, healthStat) {
      this->weapon = "Staff";
    }

// Executes the Wizard’s special skill.
// Deals magic damage proportional to mana and reduces Wizard's own health.
void Wizard::useSpecialSkill(Entity* entity) {
  if (!entity) {
    if (gameText) std::cout << name << " tried to attack, but there's no target!\n";
    return;
  }
  if (specialSkillCounter > 0) {
    if (gameText) {
      cout << "The Wizard summons a fireball out of nowhere!" << endl;
      cout << "Wizard uses up a portion of their life force." << endl;
      cout << "Wizards mana has increased!" << endl;
    }

    float damage = 2 * mana;
    entity->takeDamage(damage);

    mana += 10;  // Increase mana
    healthStat = healthStat - 30;  // Wizard sacrifices some health
    specialSkillCounter -= 1;
  } else if (gameText) {
    cout << "You have used up all your special skill charges." << endl;
  }
}

// Destructor.
Wizard::~Wizard() = default;
