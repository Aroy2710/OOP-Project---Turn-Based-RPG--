#include "Human.h"



Human::Human() : Enemy() {
  this->typeName = "Human";
}

Human::Human(float attackStat, float defenseStat, float healthStat)
    : Enemy(attackStat, defenseStat, healthStat) {
  this->typeName = "Human";
}

void Human::useSpecialSkill(Entity* target) {
  float damage = attackStat *1.2;
  if (doubleDamage) damage *= 2.0f;
  if (gameText) std::cout << typeName << " uses Piercing Strike!" << std::endl;
  target->takeDamage(damage);
}

void Human::performTurn(Entity* target) {
  // Generate a random number from 0 to 99.
  // Create a static random generator once (not every turn)
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(0, 99);
  int randomAction = dist(gen);  // truly random in [0, 99]
  // Probability Map:
  // Basic Attack:     60% (Interval 0–59)
  // Piercing Strike:  30% (Interval 60–89)
  // Defend:           10% (Interval 90–99)
  if (randomAction < 60) {
    // 60% chance: Basic Attack
    basicAttack(target);
  } else if (randomAction < 90) {
    // 30% chance: Piercing Strike
    useSpecialSkill(target);
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
