#include "Enemy.h"
#include <iostream>

using namespace std;

// Default constructor.
// Initializes an Enemy with generic attributes.
Enemy::Enemy() {
  typeName = "Enemy";
  attackStat = 40.0f;
  defenseStat = 30.0f;
  healthStat = 2000.0f;
  maxHealth = 2000.0f;
  isDefending = false;
}

// Parameterized constructor.
// Initializes an Enemy with specific stats.
Enemy::Enemy(float attackStat, float defenseStat, float healthStat) {
  this->attackStat = attackStat;
  this->defenseStat = defenseStat;
  this->healthStat = healthStat;
  maxHealth = healthStat;
  typeName = "Enemy";
  isDefending = false;
}

// Getter methods
string Enemy::getTypeName() const { return typeName; }

float Enemy::getAttackStat() const { return attackStat; }

float Enemy::getDefenseStat() const { return defenseStat; }

float Enemy::getHealthStat() const { return healthStat; }

// Setter methods with validation
void Enemy::setAttackStat(float attackStat) {
  this->attackStat = attackStat < 0.0f ? 0.0f : attackStat;
}

void Enemy::setDefenseStat(float defenseStat) {
  this->defenseStat = defenseStat < 0.0f ? 0.0f : defenseStat;
}

void Enemy::setHealthStat(float healthStat) {
  this->healthStat = healthStat < 0.0f ? 0.0f : healthStat;
}

// Executes a basic attack on another entity.
void Enemy::basicAttack(Action* target) {
  float damage = attackStat;
  if (!target) {
    if (gameText) cout << typeName << " tried to attack, but there's no target!\n";
    return;
  }
  if (gameText) cout << typeName << " attacks." << endl;
  target->takeDamage(damage);
}

// Sets the enemy to a defending state for the next turn.
void Enemy::defend() {
  isDefending = true;
  if (gameText) cout << typeName << " defends." << endl;
}

// Handles how the Enemy takes damage during battle.
// - If defending: damage is halved.
// - If not defending: defense stat reduces incoming damage.
// Health is clamped to zero to avoid negative values.
void Enemy::takeDamage(float damage) {
  if (damage < 0.0f) {
    damage = 0.0f;
  }

  if (isDefending) {
    // Defending halves all incoming damage.
    damage *= 0.5f;
    healthStat -= damage;

    if (gameText) {
      cout << typeName << " has taken " << damage << " damage." << endl;
      cout << typeName << " is no longer defending." << endl;
    }

    isDefending = false;

  } else {
    // Non-defending damage is reduced by the defense stat.
    damage -= defenseStat;
    if (damage < 0.0f) {
      damage = 0.0f;
    }

    healthStat -= damage;

    if (gameText) {
      cout << typeName << " has taken " << damage << " damage." << endl;
    }
  }

  // Clamp health to zero.
  if (healthStat < 0.0f) {
    healthStat = 0.0f;
  }
}


void Enemy::useSpecialSkill(Action* target)
{
  (void)target;  // suppress unused warning
  
}
