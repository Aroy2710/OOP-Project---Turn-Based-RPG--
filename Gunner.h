#ifndef __GUNNER_H__
#define __GUNNER_H__

#include "Ranger.h"

// Represents a Gunner-type player focusing on high-damage ranged attacks
// and improved defense through skill use.
class Gunner : public Ranger {
 public:
  // Default constructor initializes a Gunner with base stats.
  Gunner();

  // Constructs a Gunner with the given name.
  Gunner(string name);

  // Fully parameterized constructor initializing all stats and weapon.
  Gunner(string name, string weapon, float attackStat, float defenseStat,
         float healthStat);

  // Executes the Gunner's special skill on the target entity.
  void useSpecialSkill(Action* entity) override;

  // Destructor cleans up any allocated resources.
  ~Gunner();
};

#endif  // __GUNNER_H__
