#include "Goblin.h"
#include <iostream>
#include <cstdlib>

Goblin::Goblin() : Enemy("Goblin", 35.0f, 25.0f, 800.0f) {}
Goblin::Goblin(float attackStat, float defenseStat, float healthStat)
    : Enemy("Goblin", attackStat, defenseStat, healthStat) {}

void Goblin::bleedDamage(Action* target) {
    float damage = attackStat * 1.3f + (damageBoost ? extraDamage : 0);
    if (gameText) std::cout << typeName << " uses Bleed Damage!" << std::endl;
    target->takeDamage(damage);
}

void Goblin::performTurn(Action* target) {
    int r = rand() % 100;

    if (r < 65) {
        basicAttack(target);
        if (damageBoost) extraDamage += 2;
    } else if (r < 95) {
        defend();
    } else {
        bleedDamage(target);
        if (damageBoost) extraDamage += 2;
    }
}

void Goblin::onLowHP() {
    if (gameText) std::cout << typeName << " becomes desperate! Gains damage per attack!" << std::endl;
    damageBoost = true;
    extraDamage = 0;
}
