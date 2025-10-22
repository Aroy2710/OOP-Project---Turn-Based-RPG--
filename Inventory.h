#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <string>
#include <vector>

#include "HealthPotion.h"
#include "AttackPotion.h"
#include "DefensePotion.h"

using namespace std;

// Forward declaration to avoid circular dependency
class Player;

// The Inventory class aggregates items that the player can use to
// increase their stats.
class Inventory {
 public:
  explicit Inventory(Player* owner);  // Constructor
  ~Inventory();                       // Destructor

  void addItem(Item* item);            // Adds an item to the inventory
  void removeItem(string itemName);         // Removes an item from the inventory
  std::string listItems() const;       // Displays all the items in the inventory
  void use(string name);                // Uses an item

  void setGameTextForAll(bool value);  // Sets the gameText flag for all items in the inventory

 private:
  Player* owner;               // Pointer to the player (for stat changes)
  std::vector<Item*> items;    // Aggregated item objects
};

#endif  // INVENTORY_H_
