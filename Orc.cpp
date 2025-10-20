#include "Orc.h"


using namespace std;

// Default constructor.
// Initializes an Orc with default Enemy stats.
Orc::Orc() : Enemy() {
  typeName = "Orc";
}

// Parameterized constructor.
// Initializes an Orc with specific stats.
Orc::Orc(float attackStat, float defenseStat, float healthStat)
    : Enemy(attackStat, defenseStat, healthStat) {
  typeName = "Orc";
}

// Special attack: Brute Force.
// Deals damage based on attack and defense stats.
void Orc::useSpecialSkill(Entity* target) {
  float damage = attackStat * 1.2f + defenseStat * 0.5f;

  if (gameText) {
    cout << typeName << " uses Brute Force!" << endl;
  }

  target->takeDamage(damage);
}

// Defines the Orc's behavior during its turn.
// Defines the Orc's behavior during its turn.
// Uses probability to decide between Basic Attack, Defend, or Bleed Damage.
// Defines the Orc's behavior during its turn.
// If aggressive, always brute forces enemy. Otherwise, uses probability to choose an action.
void Orc::performTurn(Entity* target) {
  if (aggressive) {
    // Aggressive Orc always attacks
    useSpecialSkill(target);
    return;
  }

  // Non-aggressive Orc: choose action based on probability
  int randomAction = rand() % 100;

  // Probability map:
  // Basic Attack: 65% (0-64)
  // Defend:       30% (65-94)
  // Bleed Damage:  5% (95-99)
  if (randomAction < 65) {
    basicAttack(target);

  } else if (randomAction < 95) {
    if (!isDefending) {
      defend();
    } else {
      // If already defending, fallback to Basic Attack
      basicAttack(target);
    }

  } else {
    useSpecialSkill(target);
  }
}



// Triggered when Orc HP is low.
// Orc goes berserk, becomes aggressive, and increases stats.
void Orc::onLowHP() {
  if (gameText) {
    cout << typeName << " goes berserk! No longer defends! Orc will now do brute force" << endl;
  }

  attackStat *= 1.5f;
  defenseStat *= 1.5f;
  aggressive = true;
}
