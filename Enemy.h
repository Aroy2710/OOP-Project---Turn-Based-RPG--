#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Action.h"
#include <iostream>
using namespace std;
class Enemy : public Action {
 public:
  Enemy();
  Enemy(float attackStat, float defenseStat, float healthStat);

  virtual ~Enemy() = default;

  std::string getTypeName() const;
  float getAttackStat() const;
  float getDefenseStat() const;
  float getHealthStat() const;

  void setAttackStat(float attackStat);
  void setDefenseStat(float defenseStat);
  void setHealthStat(float healthStat);

  void basicAttack(Action* entity, float damage) override;
  void defend();
  void takeDamage(float damage) override;

  virtual void onLowHP() = 0;
  
  virtual void performTurn(Action* target) = 0;

  virtual void useSpecialSkill(Action* target);

 protected:
  string typeName;
  float attackStat;
  float defenseStat;
  float healthStat;
  float maxHealth;
  bool isDefending = false;
  bool gameText = true;
};

#endif
