#ifndef __SWORDSMAN_H__
#define __SWORDSMAN_H__

#include "Warrior.h"

// Represents a Warrior-type player focused on raw power and aggression,
// trading defense or health for increased strength through special abilities.
class Swordsman : public Warrior {
 public:
  // Default constructor initializes a Swordsman with base stats.
  Swordsman();

  // Constructs a Swordsman with the given name.
  Swordsman(string name);

  // Fully parameterized constructor initializing all stats and weapon.
  Swordsman(string name, string weapon, float attackStat, float defenseStat,
            float healthStat);

  // Executes the Swordsman's special skill on the target entity.
  void piercingBlade(Action* entity);

  // Destructor cleans up any allocated resources.
  ~Swordsman();
};

#endif // __SWORDSMAN_H__
