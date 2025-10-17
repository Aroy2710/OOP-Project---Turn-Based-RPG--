#include "Warlock.h"

// Default constructor initializes a Warlock with base Mage stats.
Warlock::Warlock() : Mage() {}

// Constructor with a name.
Warlock::Warlock(string name) : Mage(name) {}

// Fully parameterized constructor.
Warlock::Warlock(string name, string weapon, float attackStat, float defenseStat,
                 float healthStat)
    : Mage(name, weapon, attackStat, defenseStat, healthStat) {}

// Executes the Warlock's special skill on the target entity.
// Deals damage proportional to 25% of Warlock's health and consumes a skill charge.
void Warlock::eldritchBlast(Action* entity) {
  if (!entity) {
    if (gameText) std::cout << name << " tried to attack, but there's no target!\n";
    return;
  }
  if (gameText) {
    cout << "The Warlock shouts ELDRITCH BLAST!" << endl;
  }

  if (specialSkillCounter > 0) {
    float damage = 0.25f * maxHealth;

    // Apply damage to the target entity.
    entity->takeDamage(damage);

    // Optional: Warlock gains a small health boost after using the skill.
    healthStat += 30;
    maxHealth += 30;

    specialSkillCounter -= 1;
  } else if (gameText) {
    cout << "You have used up all your special skill charges." << endl;
  }
}

// Destructor.
Warlock::~Warlock() = default;
