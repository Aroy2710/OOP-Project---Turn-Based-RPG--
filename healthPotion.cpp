#include "healthPotion.h"

HealthPotion::HealthPotion() {
    itemName = "Health Potion";
    effectValue = 200;
}

HealthPotion::HealthPotion(string name, int healAmount) {
    this->itemName = name;
    this->effectValue = healAmount;
}

void HealthPotion::use(Player* player) {
    int current = player->getHealth();
        player->setHealth(current + effectValue);

        std::cout << player->getName() << " used " << itemName
                  << " and restored " << effectValue << " health!\n";
}



