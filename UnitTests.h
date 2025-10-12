#ifndef __UNITTESTS_H__
#define __UNITTESTS_H__

#include "Player.h"
#include "Ranger.h"
#include "Warrior.h"
#include "Mage.h"

// TestPlayer is a minimal subclass of Player used for unit testing.
// It implements the pure virtual method useUltimateSkill with an empty body.
class TestPlayer : public Player {
 public:
  // Constructs a TestPlayer with the given name, weapon, attack, defense, and
  // health stats.
  TestPlayer(string name, string weapon, float atk, float def, float hp)
      : Player(name, weapon, atk, def, hp) {}

  // Provides an empty implementation of useUltimateSkill to make this class
  // concrete.
  void useUltimateSkill(Action* entity) override {
    (void)entity;  // Avoid unused parameter warning.
    // Intentionally left empty for testing purposes.
  }
};

// UnitTests contains a collection of methods that test (Normal Operations) various functionalities
// of the Player, Ranger, and Warrior classes.
class UnitTests {
 public:
  // Executes all defined test methods sequentially.
  void runNormalOperationTests() {
    testPlayerGetters();
    testSettersExpectedParameters();
    testSettersNegativeParameters();
    testDefend();
    testTakeDamage();
    testTakeNegativeDamage();
    testBasicAttack();
    testRangerGetter();
    testBoostDex();
    testRangerUltimate();
    testWarriorGetter();
    testBoostStrength();
    testWarriorUltimate();
    testMageGetter();
    testBoostMana();
    testMageUltimate();
  }

 private:
  // Verifies that getter methods in the Player class correctly return the
  // initialized attributes.
  void testPlayerGetters() {
    bool allPassed = true;
    TestPlayer p("Hero", "Sword", 50, 30, 100);

    if (p.getName() != "Hero") {
      cout << "Player Name getter test failed! Expected: Hero, Got: "
           << p.getName() << endl;
      allPassed = false;
    }
    if (p.getWeapon() != "Sword") {
      cout << "Player Weapon getter test failed! Expected: Sword, Got: "
           << p.getWeapon() << endl;
      allPassed = false;
    }
    if (p.getAttackStat() != 50) {
      cout << "Attack Stat getter test failed! Expected: 50, Got: "
           << p.getAttackStat() << endl;
      allPassed = false;
    }
    if (p.getDefenseStat() != 30) {
      cout << "Defense Stat getter test failed! Expected: 30, Got: "
           << p.getDefenseStat() << endl;
      allPassed = false;
    }
    if (p.getHealthStat() != 100) {
      cout << "Health Stat getter test failed! Expected: 100, Got: "
           << p.getHealthStat() << endl;
      allPassed = false;
    }
    if (allPassed) {
      cout << "All Player getter tests passed!" << endl;
    }
  }

  // Verifies that setter methods correctly update Player stats when given
  // valid positive values.
  void testSettersExpectedParameters() {
    bool allPassed = true;
    TestPlayer p("Hero", "Sword", 50, 30, 100);

    p.setAttackStat(70);
    if (p.getAttackStat() != 70) {
      cout << "Attack Stat setter test failed! Expected: 70, Got: "
           << p.getAttackStat() << endl;
      allPassed = false;
    }

    p.setDefenseStat(40);
    if (p.getDefenseStat() != 40) {
      cout << "Defense Stat setter test failed! Expected: 40, Got: "
           << p.getDefenseStat() << endl;
      allPassed = false;
    }

    p.setHealthStat(120);
    if (p.getHealthStat() != 120) {
      cout << "Health Stat setter test failed! Expected: 120, Got: "
           << p.getHealthStat() << endl;
      allPassed = false;
    }

    if (allPassed) {
      cout << "Player setters: All expected parameter tests passed!" << endl;
    }
  }

  // Verifies that Player stat setters handle negative values safely by
  // resetting attributes to zero.
  void testSettersNegativeParameters() {
    bool allPassed = true;
    TestPlayer p("Hero", "Sword", 30, 30, 100);

    p.setAttackStat(-70);
    if (p.getAttackStat() != 0) {
      cout << "Attack Stat setter test failed! Expected: 0, Got: "
           << p.getAttackStat() << endl;
      allPassed = false;
    }

    p.setDefenseStat(-40);
    if (p.getDefenseStat() != 0) {
      cout << "Defense Stat setter test failed! Expected: 0, Got: "
           << p.getDefenseStat() << endl;
      allPassed = false;
    }

    p.setHealthStat(-120);
    if (p.getHealthStat() != 0) {
      cout << "Health Stat setter test failed! Expected: 0, Got: "
           << p.getHealthStat() << endl;
      allPassed = false;
    }

    p.setWeapon("Bow");
    if (p.getWeapon() != "Bow") {
      cout << "Weapon setter test failed! Expected: Bow, Got: "
           << p.getWeapon() << endl;
      allPassed = false;
    }

    if (allPassed) {
      cout << "Player setters: All negative parameter tests passed!" << endl;
    }
  }

  // Verifies that the defend method correctly halves incoming damage when
  // defending and properly reduces health to zero when damage is fatal.
  void testDefend() {
    bool allPassed = true;
    TestPlayer p("Hero", "Sword", 50, 30, 100);
    p.gameText = false;

    p.defend();
    p.takeDamage(40);
    if (p.getHealthStat() != 80) {
      cout << "Defend test 1 failed! Expected: 80, Got: "
           << p.getHealthStat() << endl;
      allPassed = false;
    }

    p.defend();
    p.setHealthStat(100);
    p.takeDamage(1000);
    if (p.getHealthStat() != 0) {
      cout << "Defend test 2 failed! Expected: 0, Got: "
           << p.getHealthStat() << endl;
      allPassed = false;
    }

    if (allPassed) {
      cout << "All defend tests passed!" << endl;
    }
  }

  // Verifies that takeDamage correctly reduces Player health under various
  // attack-to-defense conditions.
  void testTakeDamage() {
    bool allPassed = true;
    TestPlayer p("Hero", "Sword", 50, 30, 100);
    p.gameText = false;

    p.takeDamage(40);
    if (p.getHealthStat() != 90) {
      cout << "Take damage test 1 failed! Expected: 90, Got: "
           << p.getHealthStat() << endl;
      allPassed = false;
    }

    p.setHealthStat(100);
    p.takeDamage(30);
    if (p.getHealthStat() != 100) {
      cout << "Take damage test 2 failed! Expected: 100, Got: "
           << p.getHealthStat() << endl;
      allPassed = false;
    }

    p.setHealthStat(100);
    p.takeDamage(0);
    if (p.getHealthStat() != 100) {
      cout << "Take damage test 3 failed! Expected: 100, Got: "
           << p.getHealthStat() << endl;
      allPassed = false;
    }

    p.takeDamage(1000);
    if (p.getHealthStat() != 0) {
      cout << "Take damage test 4 failed! Expected: 0, Got: "
           << p.getHealthStat() << endl;
      allPassed = false;
    }

    if (allPassed) {
      cout << "All expected damage tests passed!" << endl;
    }
  }

  // Verifies that negative damage values do not affect Player health.
  void testTakeNegativeDamage() {
    bool allPassed = true;
    TestPlayer p("Hero", "Sword", 50, 30, 100);
    p.gameText = false;

    p.takeDamage(-20);
    if (p.getHealthStat() != 100) {
      cout << "Negative damage test failed! Expected: 100, Got: "
           << p.getHealthStat() << endl;
      allPassed = false;
    }

    if (allPassed) {
      cout << "Negative damage tests passed!" << endl;
    }
  }

  // Verifies that basicAttack applies correct damage to another entity and caps
  // health at zero when lethal.
  void testBasicAttack() {
    bool allPassed = true;

    TestPlayer* attacker = new TestPlayer("Hero", "Sword", 50, 30, 100);
    TestPlayer* defender = new TestPlayer("Villain", "Axe", 40, 20, 100);
    attacker->gameText = false;
    defender->gameText = false;

    attacker->basicAttack(defender, 25);
    if (defender->getHealthStat() != 95) {
      cout << "BasicAttack test failed! Expected defender health: 95, Got: "
           << defender->getHealthStat() << endl;
      allPassed = false;
    }

    defender->setHealthStat(100);
    attacker->basicAttack(defender, 121);
    if (defender->getHealthStat() != 0) {
      cout << "BasicAttack test failed! Expected defender health: 0, Got: "
           << defender->getHealthStat() << endl;
      allPassed = false;
    }

    if (allPassed) {
      cout << "Basic Attack tests passed!" << endl;
    }

    delete attacker;
    delete defender;
  }

  // Verifies that Ranger getter returns the correct computed dexterity value.
  void testRangerGetter() {
    Ranger r("abcd", "bow", 50, 30, 100);
    if (r.getDexterity() != 75) {
      cout << "Test failed. Expected: 75, Got: " << r.getDexterity() << endl;
    } else {
      cout << "Ranger getter tests passed!" << endl;
    }
  }

  // Verifies that Ranger boostDex correctly increments dexterity with each use
  // and stops when all boost charges are used.
  void testBoostDex() {
    bool allPassed = true;
    Ranger r("abcd", "bow", 50, 30, 100);
    r.gameText = false;

    r.boostDex();
    if (r.getDexterity() != 105) {
      cout << "Test failed. Expected: 105, Got: " << r.getDexterity() << endl;
      allPassed = false;
    }

    r.boostDex();
    r.boostDex();
    r.boostDex();
    if (r.getDexterity() != 165) {
      cout << "Test failed. Expected: 165, Got: " << r.getDexterity() << endl;
      allPassed = false;
    }

    if (allPassed) {
      cout << "All boostDex tests passed!" << endl;
    }
  }

  // Verifies that Ranger ultimate attack deals correct damage and respects
  // cooldowns and defense effects.
  void testRangerUltimate() {
    bool allPassed = true;
    Ranger r1("abcd", "bow", 50, 30, 100);
    Ranger* r2 = new Ranger("efgh", "bow", 50, 30, 1000);
    r1.gameText = false;
    r2->gameText = false;

    r1.useUltimateSkill(r2);
    if (r2->getHealthStat() != 895) {
      cout << "Test failed. Expected: 895, Got: " << r2->getHealthStat()
           << endl;
      allPassed = false;
    }

    r1.useUltimateSkill(r2);
    if (r2->getHealthStat() != 895) {
      cout << "Test failed. Expected: 895, Got: " << r2->getHealthStat()
           << endl;
      allPassed = false;
    }

    Ranger r3("abcd", "bow", 50, 30, 100);
    Ranger* r4 = new Ranger("efgh", "bow", 50, 30, 1000);
    r3.gameText = false;
    r4->gameText = false;
    r4->defend();

    r3.useUltimateSkill(r4);
    if (r4->getHealthStat() != 932.5) {
      cout << "Ultimate skill test failed. Expected: 932.5, Got: "
           << r4->getHealthStat() << endl;
      allPassed = false;
    }

    if (allPassed) {
      cout << "All Ranger ultimate tests passed!" << endl;
    }

    delete r2;
    delete r4;
  }

  // Verifies that Warrior getter returns the correct computed strength value.
  void testWarriorGetter() {
    Warrior w("abcd", "club", 50, 30, 100);
    if (w.getStrength() != 25) {
      cout << "Test failed. Expected: 25, Got: " << w.getStrength() << endl;
    } else {
      cout << "Warrior getter tests passed!" << endl;
    }
  }

  // Verifies that Warrior boostStrength correctly increments strength with
  // each use and stops once charges are depleted.
  void testBoostStrength() {
    bool allPassed = true;
    Warrior w("abcd", "club", 50, 30, 100);
    w.gameText = false;

    w.boostStrength();
    if (w.getStrength() != 55) {
      cout << "Test failed. Expected: 55, Got: " << w.getStrength() << endl;
      allPassed = false;
    }

    w.boostStrength();
    w.boostStrength();
    w.boostStrength();
    if (w.getStrength() != 115) {
      cout << "Test failed. Expected: 115, Got: " << w.getStrength() << endl;
      allPassed = false;
    }

    if (allPassed) {
      cout << "All boostStrength tests passed!" << endl;
    }
  }

  // Verifies that Warrior ultimate skill applies correct damage scaling
  // depending on current health percentage and enforces cooldown limits.
  void testWarriorUltimate() {
    bool allPassed = true;

    Warrior w1("abcd", "club", 50, 30, 100);
    Warrior* w2 = new Warrior("efgh", "club", 50, 30, 1000);
    w1.gameText = false;
    w2->gameText = false;

    w1.useUltimateSkill(w2);
    if (w2->getHealthStat() != 930) {
      cout << "Test failed. Expected: 930, Got: " << w2->getHealthStat()
           << endl;
      allPassed = false;
    }

    w1.useUltimateSkill(w2);
    if (w2->getHealthStat() != 930) {
      cout << "Test failed. Expected: 930, Got: " << w2->getHealthStat()
           << endl;
      allPassed = false;
    }

    Warrior w3("abcd", "club", 50, 30, 100);
    Warrior* w4 = new Warrior("efgh", "club", 50, 30, 1000);
    w3.gameText = false;
    w4->gameText = false;
    w3.setHealthStat(40);

    w3.useUltimateSkill(w4);
    if (w4->getHealthStat() != 830) {
      cout << "Test failed. Expected: 830, Got: " << w4->getHealthStat()
           << endl;
      allPassed = false;
    }

    if (allPassed) {
      cout << "All Warrior ultimate tests passed!" << endl;
    }

    delete w2;
    delete w4;
  }
  void testMageGetter() {
    Mage m("abcd", "club", 50, 30, 100);
    if (m.getMana() != 100) {
      cout << "Test failed. Expected: 100, Got: " << m.getMana() << endl;
    } else {
      cout << "Mage getter tests passed!" << endl;
    }
  }
  void testBoostMana() {
    bool allPassed = true;
    Mage m("abcd", "staff", 50, 30, 100);
    m.gameText = false;

    m.boostMana();
    if (m.getMana() != 130) {
      cout << "Test failed. Expected: 130, Got: " << m.getMana() << endl;
      allPassed = false;
    }

    m.boostMana(); // mana = 160
    m.boostMana(); // mana = 190
    m.boostMana(); // mana = 190
    if (m.getMana() != 190) {
      cout << "Test failed. Expected: 190, Got: " << m.getMana() << endl;
      allPassed = false;
    }

    if (allPassed) {
      cout << "All boostMana tests passed!" << endl;
    }
  }

  // Verifies that Ranger ultimate attack deals correct damage and respects
  // cooldowns and defense effects.
  void testMageUltimate() {
    bool allPassed = true;
    Mage m1("abcd", "Staff", 50, 30, 100);
    Mage* m2 = new Mage("efgh", "bow", 50, 30, 1000);
    m1.gameText = false;
    m2->gameText = false;

    //ultimate damage =  2*50 + 2*100 = 300 , hp = 1000 + 30 - 300
    m1.useUltimateSkill(m2);
    if (m2->getHealthStat() != 730) {
      cout << "Test failed. Expected: 730, Got: " << m2->getHealthStat()
           << endl;
      allPassed = false;
    }

    m1.useUltimateSkill(m2);
    if (m2->getHealthStat() != 730) {
      cout << "Test failed. Expected: 730, Got: " << m2->getHealthStat()
           << endl;
      allPassed = false;
    }

    if (allPassed) {
      cout << "All Mage ultimate tests passed!" << endl;
    }

    delete m2;
  }

};

#endif  // __UNITTESTS_H__
