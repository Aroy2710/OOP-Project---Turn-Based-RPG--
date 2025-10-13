#include "Human.h"
#include <iostream>
#include <cstdlib>

Human::Human() : Player("Human", "", 40.0f, 30.0f, 1000.0f) {
}

Human::Human(float attackStat, float defenseStat, float healthStat)
    : Player("Human", "", attackStat, defenseStat, healthStat) {}

void Human::bruteForce(Action* entity) {
    if (gameText) {
        std::cout << name << " uses Brute Force!" << std::endl;
    }
    float damage = attackStat * 2.0f;
    entity->takeDamage(damage);
}

void Human::useUltimateSkill(Action* entity) {
    if (ultimateCounter > 0) {
        if (gameText) {
            std::cout << name << " uses Ultimate Brute Force!" << std::endl;
        }
        float damage = attackStat * 3.0f;
        entity->takeDamage(damage);
        ultimateCounter--;
    } else if (gameText) {
        std::cout << name << " has no Ultimate skill uses left!" << std::endl;
    }
}

void Human::performTurn(Action* target) {
    int randomAction = rand() % 100;

    if (randomAction < 60) {
        basicAttack(target, attackStat);
    } else if (randomAction < 90) {
        bruteForce(target);
    } else {
        if (!isDefending) {
            defend();
        } else {
            basicAttack(target, attackStat);
        }
    }
}

Human::~Human() = default;
