#ifndef HEALTHPOTION_H_
#define HEALTHPOTION_H_

#include <string>

using namespace std;

#include "Item.h"

class HealthPotion : public Item {
 public:
  HealthPotion(); // Default constructor
  HealthPotion(string name, int healAmount); // Constructor: takes name first, then heal amount
  ~HealthPotion();  // Destructor

  // Override from Item
  void use(Player* target) override;
};

#endif  // HEALTHPOTION_H_
