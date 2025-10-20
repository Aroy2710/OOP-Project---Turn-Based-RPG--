#ifndef __WARLOCK_H__
#define __WARLOCK_H__

#include "Mage.h"

// Represents a Mage-type player specializing in high magic damage
// and mana-based offensive abilities.
class Warlock : public Mage {
 public:
  // Default constructor initializes a Warlock with base Mage stats.
  Warlock();

  // Constructor with a name.
  Warlock(string name);

  // Fully parameterized constructor initializing name, weapon, and stats.
  Warlock(string name, string weapon, float attackStat, float defenseStat,
          float healthStat);

  // Executes the Warlock's special skill on the target entity.
  void useSpecialSkill(Entity* entity) override;

  // Destructor.
  ~Warlock();
};

#endif  // __WARLOCK_H__
