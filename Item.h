#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
#include <string>

using namespace std;

class Player; // Forward declaration

// The Item class is an abstract base class defining a virtual Use()
// method. Derived item types override this method to modify different
// player stats.
class Item {
 public:

  bool gameText;         // Controls whether items output to console when used

  Item(string name, int value);              // Constructor
  virtual ~Item() = default;                 // Virtual destructor

  virtual void use(Player* target) = 0;      // Must be overridden by subclasses

  std::string getName() const;               // Returns the item's name
  void setName(string name);                 // Sets the item's name

 protected:
  std::string itemName;  // The item's name
  int effectValue;       // The effect value that modifies a stat
};

#endif  // ITEM_H_
