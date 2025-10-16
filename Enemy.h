#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <string>
#include "Action.h"

class Enemy : public Action {
 public:
  Enemy();
  Enemy(const std::string& typeName, float attackStat, float defenseStat, float healthStat);

  virtual ~Enemy() = default;

  std::string getTypeName() const;
  float getAttackStat() const;
  float getDefenseStat() const;
  float getHealthStat() const;

  void setAttackStat(float attackStat);
  void setDefenseStat(float defenseStat);
  void setHealthStat(float healthStat);

  void basicAttack(Action* target);
  void defend();
  void takeDamage(float damage) override;

  // Only this function is abstract, subclasses must implement it
  virtual void onLowHP() = 0;

  // The enemy does not have an ultimate—no override needed.
  // But method included for interface consistency
  virtual void useUltimateSkill(Action* target);
  
  virtual void performTurn(Action* target) = 0;

 protected:
  std::string typeName;
  float attackStat;
  float defenseStat;
  float healthStat;
  float maxHealth;
  bool isDefending = false;
  bool gameText = true;
};

#endif
