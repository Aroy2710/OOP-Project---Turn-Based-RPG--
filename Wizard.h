#ifndef __WIZARD_H__
#define __WIZARD_H__

#include "Mage.h"

// Represents a Wizard-type player who specializes in high magic damage
// and mana-based offensive abilities.
class Wizard : public Mage {
 public:
  // Default constructor initializes a Wizard with base stats.
  Wizard();

  // Constructs a Wizard with the given name.
  Wizard(string name);

  // Fully parameterized constructor initializing all stats and weapon.
  Wizard(string name, string weapon, float attackStat, float defenseStat,
         float healthStat);

  // Executes the Wizard's special skill on the target entity.
  void useSpecialSkill(Entity* entity) override;

  // Destructor cleans up any allocated resources.
  ~Wizard();
};

#endif  // __WIZARD_H__
