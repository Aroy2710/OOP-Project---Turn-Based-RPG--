#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
using namespace std;

// Forward declaration of Player class to avoid errors
class Player;

// The base item class defines the virtual use() function
// The three inherited items will then override this function
// since they each change a different stat
class Item {

    protected:
        string itemName; // The item's name
        int effectValue; // The amount that the items will change the selected stat
    
    public:
        Item(string name, int value); // Constructor
        virtual ~Item() = default;    // Destructor

        virtual void use(Player* target) = 0; // Defines the use() function that must be overriden
        string getName() const;               // Prints the name of the item
        void setName(string name);            // Changes the name of the item
};

#endif