#ifndef __ORCS_H__
#define __ORCS_H__

#include "Enemy.h"

// Represents an Orc enemy with aggressive behavior and brute force attacks.
class Orcs : public Enemy {
 public:
  // Constructors
  Orcs();
  Orcs(float attackStat, float defenseStat, float healthStat);

  // Unique attack action for the Orc.
  void useSpecialSkill(Action* target) override;

  // Determines the Orc's behavior during its turn.
  void performTurn(Action* target) override;

  // Triggered when the Orc's HP drops below a threshold.
  void onLowHP() override;

 private:
  bool aggressive = false;  // When true, Orc always brute forces and no longer defends.
};

#endif  // __ORCS_H__
