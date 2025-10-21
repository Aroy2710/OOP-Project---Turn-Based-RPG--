#ifndef __ORC_H__
#define __ORC_H__

#include "Enemy.h"

// Represents an Orc enemy with aggressive behavior and brute force attacks.
class Orc : public Enemy {
 public:
  // Constructors
  Orc();
  Orc(float attackStat, float defenseStat, float healthStat);

  // Unique attack action for the Orc.
  void useSpecialSkill(Entity* target) override;

  // Determines the Orc's behavior during its turn.
  void performTurn(Entity* target) override;

  // Triggered when the Orc's HP drops below a threshold.
  void onLowHP() override;

 private:
  bool aggressive = false;  // When true, Orc always brute forces and no longer defends.
};

#endif  // __ORCS_H__
