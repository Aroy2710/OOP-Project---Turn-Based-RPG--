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
  void runTests() {
    testGetters();
    testSetters();
    testDefend();
  }

 private:
  void testGetters() {
    bool allPassed = true;

    TestPlayer p("Hero", "Sword", 50, 30, 100);
    if (p.getName() != "Hero") {
      cout << "Name test failed!" << endl;
      allPassed = false;
    }
    if (p.getWeapon() != "Sword") {
      cout << "Player Name test failed!" << endl;
      allPassed = false;
    }

    if (p.getAttackStat() != 50) {
      cout << "AttackStat test failed!" << endl;
      allPassed = false;
    }
    if (p.getDefenseStat() != 30) {
      cout << "DefenseStat test failed!" << endl;
      allPassed = false;
    }
    if (p.getHealthStat() != 100) {
      cout << "HealthStat test failed!" << endl;
      allPassed = false;
    }

    if (allPassed) {
      cout << "All getter tests passed!" << endl;
    }
  }
  void testSetters() {
    bool allPassed = true;

    TestPlayer p("Hero", "Sword", 50, 30, 100);

    // Test attackStat setter
    p.setAttackStat(70);
    if (p.getAttackStat() != 70) {
      cout << "AttackStat setter test failed!" << endl;
      allPassed = false;
    }

    // Test defenseStat setter
    p.setDefenseStat(40);
    if (p.getDefenseStat() != 40) {
      cout << "DefenseStat setter test failed!" << endl;
      allPassed = false;
    }

    // Test healthStat setter
    p.setHealthStat(120);
    if (p.getHealthStat() != 120) {
      cout << "HealthStat setter test failed!" << endl;
      allPassed = false;
    }

    if (allPassed) {
      cout << "All setter tests passed!" << endl;
    }
  }
  void testDefend() {
    TestPlayer p("Hero", "Sword", 50, 30, 100);
    p.gameText = false;  // sets game text off for testing

    p.defend();        // sets isDefending = true
    p.takeDamage(40);  // should halve damage

    if (p.getHealthStat() == 80)
      std::cout << "Defend test passed!\n";
    else
      std::cout << "Defend test failed! Health: " << p.getHealthStat() << "\n";
  }
};

#endif  // __PLAYERUNITTESTS_H__