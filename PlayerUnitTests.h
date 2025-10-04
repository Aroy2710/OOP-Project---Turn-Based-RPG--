#ifndef __PLAYERUNITTESTS_H__
#define __PLAYERUNITTESTS_H__

#include "Player.h"

// TestPlayer is a minimal subclass of Player used for unit testing.
// It implements the pure virtual method useUltimateSkill with an empty body.
class TestPlayer : public Player {
 public:
  // Constructs a TestPlayer with the given name, weapon, attack, defense, and
  // health stats.
  TestPlayer(string name, string weapon, int atk, int def, int hp)
      : Player(name, weapon, atk, def, hp) {}

  // Provides an empty implementation of useUltimateSkill to make this class
  // concrete.
  void useUltimateSkill(Action* entity) override {
    // avoids unused parameter warning
    (void)entity;  
    // Intentionally left empty for testing purposes.
  }
};

class PlayerUnitTests {
 public:
  void runTests() { testGetters(); }

 private:
  void testGetters() {
    bool allPassed = true;

    TestPlayer p("Hero", "Sword", 50, 30, 100);
    if (p.getName() != "Hero") {
      std::cout << "Name test failed!" << std::endl;
      allPassed = false;
    }
    if (p.getWeapon() != "Sword") {
      std::cout << "Player Name test failed!" << std::endl;
      allPassed = false;
    }

    if (p.getAttackStat() != 50) {
      std::cout << "AttackStat test failed!" << std::endl;
      allPassed = false;
    }
    if (p.getDefenseStat() != 30) {
      std::cout << "DefenseStat test failed!" << std::endl;
      allPassed = false;
    }
    if (p.getHealthStat() != 100) {
      std::cout << "HealthStat test failed!" << std::endl;
      allPassed = false;
    }

    if (allPassed) {
      std::cout << "All getter tests passed!" << std::endl;
    }
  }
};

#endif // __PLAYERUNITTESTS_H__