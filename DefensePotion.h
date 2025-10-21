#ifndef DEFENSEPOTION_H_
#define DEFENSEPOTION_H_

#include <string>

using namespace std;

#include "Item.h"

class DefensePotion : public Item {
 public:
  DefensePotion(); // Default constructor
  DefensePotion(string name, int defenseBoost); // Constructor: takes name first, then defense boost
  ~DefensePotion();  // Destructor

  // Override from Item
  void use(Player* target) override;
};

#endif  // DEFENSEPOTION_H_
