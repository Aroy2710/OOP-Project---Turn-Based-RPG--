#include "Inventory.h"

#include <algorithm>
#include <iostream>
#include <vector>

#include "Player.h"

// Constructor: Creates an instance of the Inventory class,
// storing a pointer to the owning player.
Inventory::Inventory(Player* owner) {
    this->owner = owner;
}

// Destructor: Clears the items vector.
Inventory::~Inventory() {
  items.clear();
}

// Adds an item to the end of the items vector.
void Inventory::addItem(Item* item) {
  items.push_back(item);
}

// Searches for and removes an item from the items vector.
void Inventory::removeItem(Item* item) {
  items.erase(std::remove(items.begin(), items.end(), item), items.end());
}

// Uses an item by finding it in the items vector,
// calling the item's Use() method, then removing it from the vector.
void Inventory::use(Item* item) {
  auto it = std::find(items.begin(), items.end(), item);
  if (it != items.end()) {
    item->use(owner);
    removeItem(item);
  } else {
    std::cout << item->getName() << " not found in inventory." << std::endl;
  }
}
