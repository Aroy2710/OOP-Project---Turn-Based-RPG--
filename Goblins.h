#ifndef __GOBLIN_H__
#define __GOBLIN_H__

#include "Enemy.h"

class Goblin : public Enemy {
 public:
  Goblin();
  Goblin(float attackStat, float defenseStat, float healthStat);

  void bleedDamage(Action* target);
  void performTurn(Action* target) override;
  void onLowHP() override;

 private:
  bool damageBoost = false;
  int extraDamage = 0;
};

#endif
