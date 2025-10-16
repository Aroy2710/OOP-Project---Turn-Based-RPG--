#include "Orcs.h"
#include <iostream>
#include <cstdlib>

Orcs::Orcs() : Enemy("Orcs", 55.0f, 40.0f, 1200.0f) {}
Orcs::Orcs(float attackStat, float defenseStat, float healthStat)
    : Enemy("Orcs", attackStat, defenseStat, healthStat) {}

void Orcs::piercingStrike(Action* target) {
    float damage = attackStat * 1.2f + target->getDefenseStat() * 0.5f;
    if (gameText) std::cout << typeName << " uses Piercing Strike!" << std::endl;
    target->takeDamage(damage);
}

void Orcs::performTurn(Action* target) {
    if (aggressive) {
        basicAttack(target);
    } else {
        int r = rand() % 100;
        if (r < 50)
            basicAttack(target);
        else if (r < 85)
            piercingStrike(target);
        else
            defend();
    }
}

void Orcs::onLowHP() {
    if (gameText) std::cout << typeName << " goes berserk! No longer defends!" << std::endl;
    attackStat *= 1.5f;
    aggressive = true;
}
