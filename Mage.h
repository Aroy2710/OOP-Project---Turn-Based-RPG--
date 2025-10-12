#ifndef __MAGE_H__
#define __MAGE_H__

#include "Player.h"

// Represents a Mage-type player who specializes in magic attacks,
// spellcasting, and mana-based abilities.
class Mage : public Player {
 public:
  // Default constructor initializes a Mage with base stats.
  Mage();

  // Constructs a Mage with the given name.
  explicit Mage(string name);

  // Fully parameterized constructor initializing all stats and weapon.
  Mage(string name, string weapon, float attackStat, float defenseStat,
       float healthStat);

  // Returns the current mana value of the Mage.
  float getMana();

  // Temporarily boosts the Mage's mana for a limited number of turns.
  void boostMana();

  // Executes the Mage's ultimate skill on the target entity.
  void useUltimateSkill(Action* entity) override;

  // Destructor cleans up any allocated resources.
  ~Mage();

 protected:
  // Represents the Mage's magical energy used for casting spells.
  float mana;
};

#endif  // __MAGE_H__
