#include "Inventory.h"

#include <algorithm>
#include <iostream>
#include <vector>

// Constructor: Creates an instance of the Inventory class,
// storing a pointer to the owning player.
Inventory::Inventory(Player* owner) {
    this->owner = owner;
    items.push_back(new HealthPotion("Health Potion", 200)); // default items
    //items.push_back(new AttackPotion("Attack Potion", 20)); // default items
    //items.push_back(new DefensePotion("Defense Potion", 20)); // default items
}

Inventory::~Inventory() { 
  for (Item* item : items) { 
    delete item; // free the memory of each item
  }
  items.clear(); // clear the vector of dangling pointers
  }

// Adds an item to the end of the items vector.
void Inventory::addItem(Item* item) {
  items.push_back(item);
}

// Searches for and removes an item from the items vector.
void Inventory::removeItem(Item* item) {
  items.erase(std::remove(items.begin(), items.end(), item), items.end());
}

string Inventory::listItems() const {

  if (items.empty()) {
    return "Inventory is empty.\n";
  }

  string list = "";
  for (size_t i = 0; i < items.size(); ++i) {
    if (items[i]) {
      list += items[i]->getName() + ", ";
    }
    if (i < items.size() - 1) {
      list += "\n";
    }
  }
  return list;

}

void Inventory::setGameTextForAll(bool value) {
    for (Item* item : items) {
      item->gameText = value;  // set each item's gameText
    }
}

// Uses an item by finding it in the items vector,
void Inventory::use(string name) {

  for (Item* item : items) {
    if (item && item->getName() == name) {
      item->use(owner);
      removeItem(item);
      return;
    }
  }
  std::cout << name << " not found in inventory." << std::endl;
}
