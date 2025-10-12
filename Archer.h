#ifndef __ARCHER_H__
#define __ARCHER_H__

#include "Ranger.h"

// Represents an Archer-type player specializing in precise ranged attacks
// and scaling offensive power through skill use.
class Archer : public Ranger {
 public:
  // Default constructor initializes an Archer with base stats.
  Archer();

  // Constructs an Archer with the given name.
  explicit Archer(string name);

  // Fully parameterized constructor initializing all stats and weapon.
  Archer(string name, string weapon, float attackStat, float defenseStat,
         float healthStat);

  // Executes the Archer's special skill on the target entity.
  void headShot(Action* entity);

  // Destructor cleans up any allocated resources.
  ~Archer();
};

#endif  // __ARCHER_H__
