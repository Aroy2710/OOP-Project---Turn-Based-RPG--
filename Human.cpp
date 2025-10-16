#include "Human.h"
#include <iostream>
#include <cstdlib>

Human::Human() : Enemy("Human", 45.0f, 35.0f, 1100.0f) {}
Human::Human(float attackStat, float defenseStat, float healthStat)
    : Enemy("Human", attackStat, defenseStat, healthStat) {}

void Human::bruteForce(Action* target) {
    float damage = attackStat * 1.5f;
    if (doubleDamage) damage *= 2.0f;
    if (gameText) std::cout << typeName << " uses Brute Force!" << std::endl;
    target->takeDamage(damage);
}

void Human::performTurn(Action* target) {
    int r = rand() % 100;
    if (r < 60)
        basicAttack(target);
    else if (r < 90)
        bruteForce(target);
    else
        defend();
}

void Human::onLowHP() {
    if (gameText) std::cout << typeName << " becomes enraged! Damage doubled!" << std::endl;
    doubleDamage = true;
}
