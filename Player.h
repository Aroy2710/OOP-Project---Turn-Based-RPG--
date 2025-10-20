#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <string>

using namespace std;

#include "Action.h"
#include "Inventory.h"

// The Player class defines shared attributes and actions
// for all playable archetypes (e.g., Warrior, Ranger, Mage).
// Players can attack, defend, and use special or ultimate abilities.
class Player : public Action {
 public:
  // Constructors
  Player();             // Default constructor for gameplay.
  Player(string name);  // Custom name constructor.
  Player(string name, const string weapon, float attack_stat,
         float defense_stat, float health_stat);

  // Virtual destructor ensures correct cleanup of derived classes.
  ~Player() override = default;

  // Getters
  string getName() const;
  string getWeapon() const;
  float getAttackStat() const;
  float getDefenseStat() const;
  float getHealthStat() const;
  int getUltimateCounter() const;
  int getBoostCounter() const;
  int getSpecialSkillCounter() const;
  Inventory& getInventory();
  virtual float getUniqueStat() const;

  // Setters
  void setAttackStat(float attack_stat);
  void setDefenseStat(float defense_stat);
  void setHealthStat(float health_stat);
  void setWeapon(const string weapon_name);

  // Combat methods
  void basicAttack(Action* entity) override;
  void defend() override;
  void takeDamage(float damage) override;

  // Pure virtual method for archetype-specific ultimate skill.
  virtual void useUltimateSkill(Action* entity) = 0;

  //methods for boost and special skill
  virtual void useBoost();
  void useSpecialSkill(Action* entity) override;

  // Controls console output (true = print battle messages).
  bool gameText = true;

 protected:
  // Player identity and attributes.
  string name;
  string weapon;
  string archetype;

  // Combat stats.
  float attackStat;
  float defenseStat;
  float healthStat;
  float maxHealth;

  // State flags and counters.
  bool isDefending = false;
  int ultimateCounter;
  int boostCounter;
  int specialSkillCounter;

  // Inventory
  Inventory inventory;
};

#endif  // __PLAYER_H__
