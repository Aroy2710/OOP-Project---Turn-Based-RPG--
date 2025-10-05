#include "Item.h"

Item::Item(string name, int value) {
    itemName = name;
    effectValue = value;
}

string Item::getName() const {
    return itemName;
}