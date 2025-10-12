#include "Inventory.h"
#include "Player.h"
#include <algorithm>
#include <vector>

// Constructor
// Creates an instance of the Inventory class,
// passing a pointer to the player object
Inventory::Inventory(Player* owner) {
    this->owner = owner;
}

// Destructor
// Clears the items vector
Inventory::~Inventory() {
    items.clear();
}

// Adds an item to the end of the items vector
void Inventory::addItem(Item* item) {
    items.push_back(item);
}

// Searches for, anda removes an item from the items vector
void Inventory::removeItem(Item* item) {
    items.erase(remove(items.begin(), items.end(), item), items.end());
}

// Uses an item by finding it in the items vector
// then calls the item's use() method, and removes
// it from the items vector.
void Inventory::use(Item* item) {
    auto it = find(items.begin(), items.end(), item);
    if (it != items.end()) {
        item->use(owner);
        removeItem(item);
    } else {
        cout << item->getName() << " not found in inventory." << endl;
    }
}



