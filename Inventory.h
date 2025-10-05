#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"
using namespace std;

class Player;

class Inventory {

    protected:
        Player* owner;
        vector<Item*> items;
    
    public:
        Inventory(Player* owner);
        ~Inventory();

        void addItem(Item* item);
        void removeItem(Item* item);
        string listItems();
        void use(Item* item);

};

#endif