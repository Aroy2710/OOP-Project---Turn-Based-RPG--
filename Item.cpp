#include "Item.h"

// Constructor
// Sets the name of the iteem and the amount
// that it will change  selected stat by
Item::Item(string name, int value) {
    itemName = name;
    effectValue = value;
}

// Returns the name of the item
string Item::getName() const {
    return itemName;
}

// Changes the name of the item
void Item::setName(string name) {
    this->itemName = name;
}