#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"
using namespace std;

// Forward declaration of th Player class to avoid errors
class Player;

// The inventory class aggregates items which the player
// can use to increase their stats.
class Inventory {

    protected:
        Player* owner;        // Holds a pointer to player as the target for stat changes
        vector<Item*> items;  // Aggregates item objects
    
    public:
        Inventory(Player* owner); // Constructor
        ~Inventory();             // Destructor

        void addItem(Item* item);    // Adds an item to the inventory
        void removeItem(Item* item); // Removes an item from the inventory
        string listItems();          // Displays all the items currently in the inventory
        void use(Item* item);        // Uses an item

};

#endif