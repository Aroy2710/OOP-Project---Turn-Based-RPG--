#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <string>
#include <vector>

#include "Item.h"

using namespace std;

// Forward declaration of the Player class to avoid circular dependencies.
class Player;

// The Inventory class aggregates items that the player can use to
// increase their stats.
class Inventory {
 public:
  explicit Inventory(Player* owner);  // Constructor
  ~Inventory();                       // Destructor

  void addItem(Item* item);            // Adds an item to the inventory
  void removeItem(Item* item);         // Removes an item from the inventory
  std::string listItems() const;       // Displays all the items in the inventory
  void use(Item* item);                // Uses an item

 private:
  Player* owner;               // Pointer to the player (for stat changes)
  std::vector<Item*> items;    // Aggregated item objects
};

#endif  // INVENTORY_H_
