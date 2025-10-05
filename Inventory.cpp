#include "Inventory.h"
#include "Player.h"
#include <algorithm>
#include <vector>

Inventory::Inventory(Player* owner) {
    this->owner = owner;
}

Inventory::~Inventory() {
    items.clear();
}

void Inventory::addItem(Item* item) {
    items.push_back(item);
}

void Inventory::removeItem(Item* item) {
    items.erase(remove(items.begin(), items.end(), item), items.end());
}

void Inventory::use(Item* item) {
    auto it = find(items.begin(), items.end(), item);
    if (it != items.end()) {
        item->use(owner);
        removeItem(item);
    } else {
        cout << item->getName() << " not found in inventory." << endl;
    }
}



