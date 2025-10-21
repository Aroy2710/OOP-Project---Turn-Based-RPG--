#ifndef ATTACKPOTION_H_
#define ATTACKPOTION_H_

#include <string>

using namespace std;

#include "Item.h"

class AttackPotion : public Item {
 public:
  AttackPotion(); // Default constructor
  AttackPotion(string name, int attackBoost); // Constructor: takes name first, then attack boost
  ~AttackPotion();  // Destructor

  // Override from Item
  void use(Player* target) override;
};

#endif  // ATTACKPOTION_H_
