#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Entity.h"
#include <iostream>
#include <random>
using namespace std;
class Enemy : public Entity {
 public:
  Enemy();
  Enemy(float attackStat, float defenseStat, float healthStat);

  virtual ~Enemy() = default;

  string getTypeName() const;
  float getAttackStat() const;
  float getDefenseStat() const;
  float getHealthStat() const;

  void setAttackStat(float attackStat);
  void setDefenseStat(float defenseStat);
  void setHealthStat(float healthStat);

  void basicAttack(Entity* target) override;
  void defend();
  void takeDamage(float damage) override;

  virtual void onLowHP() = 0;
  
  virtual void performTurn(Entity* target) = 0;

  virtual void useSpecialSkill(Entity* target);

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
