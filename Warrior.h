#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include "Player.h"

// Represents a Warrior-type player with enhanced strength and
// unique combat abilities such as a temporary strength boost and
// an ultimate skill.
class Warrior : public Player {
 public:
  // Default constructor initializes a Warrior with base stats.
  Warrior();

  // Constructs a Warrior with the given name.
  Warrior(string name);

  // Fully parameterized constructor initializing all stats and weapon.
  Warrior(string name, string weapon, float attackStat, float defenseStat,
          float healthStat);

  // Returns the current strength value of the Warrior.
  float getUniqueStat() const override;

  // Sets the Warrior's strength to the specified value.
  void setUniqueStat(float value) override;

  // Boosts the warriors strength
  void useBoost() override;

  // Executes the Warrior's ultimate skill on the target entity.
  void useUltimateSkill(Entity* entity) override;

  // Destructor cleans up any allocated resources.
  ~Warrior();

 protected:
  // Represents the Warrior's physical power that amplifies attack damage.
  float strength;
};

#endif  // __WARRIOR_H__
