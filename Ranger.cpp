#include "Ranger.h"

// Default constructor.
// Initializes a Ranger with default Player attributes.
// The Ranger's weapon defaults to "Bow".
// Dexterity is set to 1.5× the attack stat.
Ranger::Ranger() : Player() {
  Player::setWeapon("Bow");
  dexterity = 1.5f * attackStat;
}

// Constructor for Ranger with a custom name.
// The Ranger's weapon defaults to "Bow".
// Dexterity is set to 1.5× the attack stat.
Ranger::Ranger(std::string name) : Player(name) {
  Player::setWeapon("Bow");
  dexterity = 1.5f * attackStat;
}

// Parameterized constructor.
// Useful for testing with explicit stat values.
// Dexterity is initialized to 1.5× attack stat.
Ranger::Ranger(std::string name, std::string weapon, float attack_stat,
               float defense_stat, float health_stat)
    : Player(name, weapon, attack_stat, defense_stat, health_stat) {
  dexterity = 1.5f * attackStat;
}

// Returns the Ranger's current dexterity value.
float Ranger::getDexterity() {
  return dexterity;
}

// Increases the Ranger's dexterity temporarily.
// Each use consumes one available boost charge.
// Requires an external battle manager to enforce cooldowns.
void Ranger::boostDex() {
  if (useCounter > 0) {
    dexterity += 30.0f;
    useCounter -= 1;
  } else if (gameText) {
    std::cout << "You have used all your charges for your boost."
              << std::endl;
  }
}

// Uses the Ranger's ultimate skill on a target entity.
// The attack combines precision (dexterity) and power (attack stat).
void Ranger::useUltimateSkill(Action* entity) {
  if (ultimateCounter > 0) {
    float damage = (attackStat * 1.5f) + (dexterity * 0.8f);

    entity->takeDamage(damage);

    if (gameText) {
      std::cout << "Drawing every ounce of focus... ultimate shot fired!"
                << std::endl;
    }

    ultimateCounter -= 1;
  } else if (gameText) {
    std::cout << "You have used up your charge for your ultimate skill."
              << std::endl;
  }
}

// Destructor.
Ranger::~Ranger() = default;
