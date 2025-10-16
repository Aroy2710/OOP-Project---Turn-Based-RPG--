#include "Enemy.h"
#include <iostream>

Enemy::Enemy() : typeName("Enemy"), attackStat(40), defenseStat(30), healthStat(1000), maxHealth(1000) {}

Enemy::Enemy(const std::string& typeName, float attackStat, float defenseStat, float healthStat)
    : typeName(typeName),
      attackStat(attackStat),
      defenseStat(defenseStat),
      healthStat(healthStat),
      maxHealth(healthStat) {}

void Enemy::basicAttack(Action* target) {
    if (gameText) std::cout << typeName << " attacks." << std::endl;
    target->takeDamage(attackStat);
}

void Enemy::defend() {
    if (gameText) std::cout << typeName << " defends." << std::endl;
    isDefending = true;
}

void Enemy::takeDamage(float damage) {
    if (damage < 0.0f) damage = 0.0f;

    if (isDefending) {
        damage *= 0.5f;
        isDefending = false;
    } else {
        damage -= defenseStat;
        if (damage < 0.0f) damage = 0.0f;
    }
    healthStat -= damage;
    if (healthStat < 0.0f) healthStat = 0.0f;

    if (gameText) std::cout << typeName << " takes " << damage << " damage." << std::endl;
    if (healthStat <= 0.25f * maxHealth) {
        onLowHP();
    }
}

void Enemy::useUltimateSkill(Action* target) {

}
