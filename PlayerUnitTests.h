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
    testSettersExpectedParameters();
    testSettersNegativeParameters();
    testDefend();
    testTakeDamage();
    testTakeNegativeDamage();
  }

 private:
  void testGetters() {
    bool allPassed = true;

    TestPlayer p("Hero", "Sword", 50, 30, 100);
    if (p.getName() != "Hero") {
      cout << "Player Name getter test failed!" << endl;
      allPassed = false;
    }
    if (p.getWeapon() != "Sword") {
      cout << "Player Weapon getter test failed!" << endl;
      allPassed = false;
    }

    if (p.getAttackStat() != 50) {
      cout << "Attack Stat getter test failed!" << endl;
      allPassed = false;
    }
    if (p.getDefenseStat() != 30) {
      cout << "Defense Stat getter test failed!" << endl;
      allPassed = false;
    }
    if (p.getHealthStat() != 100) {
      cout << "Health Stat getter test failed!" << endl;
      allPassed = false;
    }

    if (allPassed) {
      cout << "All getter tests passed!" << endl;
    }
  }
  void testSettersExpectedParameters() {
    bool allPassed = true;

    TestPlayer p("Hero", "Sword", 50, 30, 100);

    // Test attackStat setter
    p.setAttackStat(70);
    if (p.getAttackStat() != 70) {
      cout << "Attack Stat setter test failed! for attack = 70" << endl;
      allPassed = false;
    }

    // Test defenseStat setter
    p.setDefenseStat(40);
    if (p.getDefenseStat() != 40) {
      cout << "Defense Stat setter test failed! for defense = 40" << endl;
      allPassed = false;
    }

    // Test healthStat setter
    p.setHealthStat(120);
    if (p.getHealthStat() != 120) {
      cout << "Health Stat setter test failed! for health = 120" << endl;
      allPassed = false;
    }

    if (allPassed) {
      cout << "Setters : All expected parameter tests passed!" << endl;
    }
  }
  void testSettersNegativeParameters() {
    TestPlayer p("Hero", "Sword", 30, 30, 100);
    bool allPassed = true;
    // Test attackStat setter
    p.setAttackStat(-70);
    if (p.getAttackStat() != 0) {
      cout << "Attack Stat setter test failed! for attack = -70" << endl;
      allPassed = false;
    }

    // Test defenseStat setter
    p.setDefenseStat(-40);
    if (p.getDefenseStat() != 0) {
      cout << "Defense Stat setter test failed! for defense = -40" << endl;
      allPassed = false;
    }

    // Test healthStat setter
    p.setHealthStat(-120);
    if (p.getHealthStat() != 0) {
      cout << "Health Stat setter test failed! for health = -120" << endl;
      allPassed = false;
    }

    if (allPassed) {
      cout << "Setters : All negative parameter tests passed!" << endl;
    }
  }

  void testDefend() {
    bool allPassed = true;
    TestPlayer p("Hero", "Sword", 50, 30, 100);
    p.gameText = false;  // sets game text off for testing
    // case : player lives
    p.defend();        // sets isDefending = true
    p.takeDamage(40);  // should halve damage

    if (p.getHealthStat() != 80){

      cout << "Defend test 1 failed! Health: " << p.getHealthStat() << "\n";
      allPassed = false;

    }

    // case: player dies
    p.defend();
    p.setHealthStat(100);  // set player health back to default
    p.takeDamage(1000);
    if (p.getHealthStat() != 0){

      cout << "Defend test 2 failed! Health: " << p.getHealthStat() << "\n";
      allPassed = false;

    }


    if (allPassed) {
      cout << "All defend tests passed!" << endl;
    }
  }
  void testTakeDamage() {
    bool allPassed = true;
    TestPlayer p("Hero", "Sword", 50, 30, 100);
    // since defend method works as intended we only test the cases where the
    // player is not defending
    p.gameText = false;  // set game text off for testing

    // when attackStat>def
    p.takeDamage(40);
    if (p.getHealthStat() != 90) {
      cout << "Take damage test 1 failed! Health: " << p.getHealthStat()
           << "\n";
      allPassed = false;
    }

    // when attackStat = def
    p.setHealthStat(100);  // reset health
    p.takeDamage(30);

    if (p.getHealthStat() != 100) {
      cout << "Take damage test 2 failed! Health: " << p.getHealthStat()
           << "\n";
      allPassed = false;
    }

    // when attackStat < def
    p.setHealthStat(100);  // reset health
    p.takeDamage(0);

    if (p.getHealthStat() != 100) {
      cout << "Take damage test 3 failed!" << p.getHealthStat() << "\n";
      allPassed = false;
    }

    // when attackStat is much greater than health
    p.takeDamage(1000);

    if (p.getHealthStat() != 0) {
      cout << "Take damage test 4 failed! Health: " << p.getHealthStat()
           << "\n";
      allPassed = false;
    }
    if (allPassed) {
      cout << "All Expected  damage tests passed!" << endl;
    }
  }
  void testTakeNegativeDamage() {
    bool allPassed = true;
    TestPlayer p("Hero", "Sword", 50, 30, 100);
    p.gameText = false;
    p.takeDamage(-20);
    if (p.getHealthStat() != 100) {
      cout << "Negative damage test  failed! Health" << p.getHealthStat();
    }
    if (allPassed) {
      cout << "Negative damage test Passed!";
    }
  }
};

#endif  // __PLAYERUNITTESTS_H__