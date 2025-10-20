#ifndef __HUMAN_H__
#define __HUMAN_H__

#include "Enemy.h"

class Human : public Enemy {
 public:
  Human();
  Human(float attackStat, float defenseStat, float healthStat);

  void useSpecialSkill(Entity* target) override;
  void performTurn(Entity* target) override;
  void onLowHP() override;

 private:
  bool doubleDamage = false;
};

#endif
