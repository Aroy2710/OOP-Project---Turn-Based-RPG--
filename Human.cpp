#include "Human.h"



Human::Human() : Enemy() {}

Human::Human(float attackStat, float defenseStat, float healthStat)
    : Enemy(attackStat, defenseStat, healthStat) {
  typeName = "Human";
}

void Human::piercingStrike(Action* target) {
  float damage = attackStat * 1.5f;
  if (doubleDamage) damage *= 2.0f;
  if (gameText) std::cout << typeName << " uses Piercing Strike!" << std::endl;
  target->takeDamage(damage);
}

void Human::performTurn(Action* target) {
  // Generate a random number from 0 to 99.
  int randomAction = rand() % 100;

  // Probability Map:
  // Basic Attack:     60% (Interval 0–59)
  // Piercing Strike:  30% (Interval 60–89)
  // Defend:           10% (Interval 90–99)
  if (randomAction < 60) {
    // 60% chance: Basic Attack
    basicAttack(target, attackStat);
  } else if (randomAction < 90) {
    // 30% chance: Piercing Strike
    piercingStrike(target);
  } else {
    // 10% chance: Defend
    defend();
  }
}

void Human::onLowHP() {
  if (gameText)
    std::cout << typeName << " becomes enraged! Damage doubled!" << std::endl;
  doubleDamage = true;
}
