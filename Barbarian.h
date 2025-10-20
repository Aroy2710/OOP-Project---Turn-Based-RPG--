#ifndef __BARBARIAN_H__
#define __BARBARIAN_H__

#include "Warrior.h"

// Represents a Warrior-type player focused on raw power and aggression,
// trading defense for increased strength through special abilities.
class Barbarian : public Warrior {
 public:
  // Default constructor initializes a Barbarian with base stats.
  Barbarian();

  // Constructs a Barbarian with the given name.
  Barbarian(string name);

  // Fully parameterized constructor initializing all stats and weapon.
  Barbarian(string name, string weapon, float attackStat, float defenseStat,
            float healthStat);

  // Executes the Barbarian's special skill on the target entity.
  void useSpecialSkill(Entity* entity) override;

  // Destructor.
  ~Barbarian();
};

#endif  // __BARBARIAN_H__
