#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <string>
#include "Action.h"

using namespace std;

class Player : public Action {
 public:
  // Constructors
  Player();             // Default constructor for gameplay
  Player(string name);  // Name provided
  Player(string name, string weapon, float attackStat, float defenseStat,
         float healthStat);  // Fully parameterized

  // Getters
  string getName() const;
  string getWeapon() const;
  float getAttackStat() const;
  float getDefenseStat() const;
  float getHealthStat() const;

  // Setters
  void setAttackStat(float attackStat);
  void setDefenseStat(float defenseStat);
  void setHealthStat(float healthStat);
  void setWeapon( string weapon);

  // Combat methods
  void basicAttack(Action* entity, float damage) override;
  void defend() override;
  void takeDamage(float damage) override;

  // Pure virtual method for ultimate skill
  virtual void useUltimateSkill(Action* entity) = 0;

  // Controls console output (true = print messages)
  bool gameText = true;

 protected:
  string name;
  string weapon;
  float attackStat;
  float defenseStat;
  float maxHealth;
  bool isDefending;
  float healthStat;
  float ultimateCounter;
  float useCounter;
};

#endif  // __PLAYER_H__
