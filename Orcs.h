#ifndef __ORCS_H__
#define __ORCS_H__

#include "Enemy.h"

class Orcs : public Enemy {
 public:
  Orcs();
  Orcs(float attackStat, float defenseStat, float healthStat);

  void piercingStrike(Action* target);
  void performTurn(Action* target) override;
  void onLowHP() override;

 private:
  bool aggressive = false;
};

#endif
