#include "Inventory.h"

#include <algorithm>
#include <iostream>
#include <vector>

// Constructor: Creates an instance of the Inventory class,
// storing a pointer to the owning player.
Inventory::Inventory(Player* owner) {
    this->owner = owner;
    items.push_back(new HealthPotion("Health Potion", 200)); // default items
    items.push_back(new AttackPotion("Attack Potion", 30)); // default items
    items.push_back(new DefensePotion("Defense Potion", 20)); // default items
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

// Removes an item from the inventory by name.
void Inventory::removeItem(string itemName) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getName() == itemName) {
            delete *it;
            items.erase(it);
            break; 
        }
    }
}


string Inventory::listItems() const {

  if (items.empty()) {
    return "Empty\n";
  }

  string list = "";
  for (size_t i = 0; i < items.size(); ++i) {
    if (i <= items.size() - 1) {
      list += items[i]->getName() + "\n";
    } else if (items[i]) {
      list += items[i]->getName() + ", ";
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
    // --- Convert player input to lowercase ---
    std::transform(name.begin(), name.end(), name.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    for (Item* item : items) {
        if (item) {
            // --- Convert item name to lowercase for comparison ---
            string itemName = item->getName();
            std::transform(itemName.begin(), itemName.end(), itemName.begin(),
                           [](unsigned char c){ return std::tolower(c); });

            if (itemName == name) {
                cout << "Using item: " << item->getName() << endl;  // Debug line
                item->use(owner);
                removeItem(item->getName());  // Remove item after use
                return;
            }
        }
    }

    throw std::invalid_argument("Item not found in inventory.");
}
