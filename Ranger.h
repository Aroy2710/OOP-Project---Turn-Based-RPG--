#ifndef __RANGER_H__
#define __RANGER_H__

#include "Player.h"

// Represents a Ranger-type player who specializes in ranged attacks,
// agility, and precision-based combat abilities.
class Ranger : public Player {
 public:
  // Default constructor initializes a Ranger with base stats.
  Ranger();

  // Constructs a Ranger with the given name.
  explicit Ranger(string name);

  // Fully parameterized constructor initializing all stats and weapon.
  Ranger(string name, string weapon, float attackStat, float defenseStat,
         float healthStat);

  // Returns the current dexterity value of the Ranger.
  float getDexterity();

  // Temporarily boosts the Ranger's dexterity , has a turn cooldown.
  void boostDex();

  // Executes the Ranger's ultimate skill on the target entity.
  void useUltimateSkill(Action* entity) override;

  // Destructor cleans up any allocated resources.
  ~Ranger();

 protected:
  // Represents the Ranger's agility and accuracy, affecting attack precision.
  float dexterity;
};

#endif  // __RANGER_H__
