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
  Player(string name, string weapon, int attackStat, int defenseStat,
         int healthStat);  // Fully parameterized

  // Getters
  string getName() const;
  string getWeapon() const;
  int getAttackStat() const;
  int getDefenseStat() const;
  int getHealthStat() const;

  // Setters
  void setAttackStat(int attackStat);
  void setDefenseStat(int defenseStat);
  void setHealthStat(int healthStat);
  void setWeapon(const string& weapon);

  // Combat methods
  void basicAttack(Action* entity, int damage) override;
  void defend() override;
  void takeDamage(int damage) override;

  // Pure virtual method for ultimate skill
  virtual void useUltimateSkill(Action* entity) = 0;

  // Controls console output (true = print messages)
  bool gameText = true;

 protected:
  string name;
  string weapon;
  int attackStat;
  int defenseStat;
  bool isDefending;
  int healthStat;
  int ultimateCounter;
  int useCounter;
};

#endif  // __PLAYER_H__
