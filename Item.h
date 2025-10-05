#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
using namespace std;

class Player;

class Item {

    protected:
        string itemName;
        int effectValue;
    
    public:
        Item(string name, int value);
        virtual ~Item() = default;
        virtual void use(Player* target) = 0;
        string getName() const;
        void setName(string name);
};

#endif