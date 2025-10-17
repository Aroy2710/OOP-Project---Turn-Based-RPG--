#ifndef __GOBLIN_H__
#define __GOBLIN_H__

#include "Enemy.h"

// Goblin class defines a specific Enemy type with unique behavior.
// Goblins can perform a basic attack, defend, and use a special
// Bleed Damage attack. They become stronger when their HP is low.
class Goblin : public Enemy {
 public:
  // Constructors
  Goblin();  // Default constructor
  Goblin(float attackStat, float defenseStat, float healthStat);  // Custom stats

  // Special attack
  void bleedDamage(Action* target);

  // Defines behavior during the Goblin's turn
  void performTurn(Action* target) override;

  // Triggered when Goblin HP is low
  void onLowHP() override;

 private:
  // State flags for special mechanics
  bool damageBoost = false;
  int extraDamage = 0;
};

#endif  // __GOBLIN_H__
