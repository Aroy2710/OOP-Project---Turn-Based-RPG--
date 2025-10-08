#ifndef __UNITTESTS_H__
#define __UNITTESTS_H__

#include "Player.h"
#include "Ranger.h"
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
    // avoids unused parameter warning
    (void)entity;
    // Intentionally left empty for testing purposes.
  }
};

class UnitTests {
 public:
  void runTests() {
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
  }

 private:
  // Tests for Players
  void testPlayerGetters() {
    bool allPassed = true;

    TestPlayer p("Hero", "Sword", 50, 30, 100);
    if (p.getName() != "Hero") {
      cout << "Player Name getter test failed! Expected : Hero , Got: "
           << p.getName() << endl;
      allPassed = false;
    }
    if (p.getWeapon() != "Sword") {
      cout << "Player Weapon getter test failed! Expected : Sword , Got: "
           << p.getWeapon() << endl;
      allPassed = false;
    }

    if (p.getAttackStat() != 50) {
      cout << "Attack Stat getter test failed! Expected : 50 , Got: "
           << p.getAttackStat() << endl;
      allPassed = false;
    }
    if (p.getDefenseStat() != 30) {
      cout << "Defense Stat getter test failed! Expected : 30 , Got: "
           << p.getDefenseStat() << endl;
      allPassed = false;
    }
    if (p.getHealthStat() != 100) {
      cout << "Health Stat getter test failed! Expected : 100 , Got: "
           << p.getHealthStat() << endl;
      allPassed = false;
    }

    if (allPassed) {
      cout << "All Player getter tests passed!" << endl;
    }
  }
  void testSettersExpectedParameters() {
    bool allPassed = true;

    TestPlayer p("Hero", "Sword", 50, 30, 100);

    // Test attackStat setter
    p.setAttackStat(70);
    if (p.getAttackStat() != 70) {
      cout << "Attack Stat setter test failed! Expected : 70 , Got: "
           << p.getAttackStat() << endl;
      allPassed = false;
    }

    // Test defenseStat setter
    p.setDefenseStat(40);
    if (p.getDefenseStat() != 40) {
      cout << "Defense Stat setter test failed! Expected : 40, Got :"
           << p.getDefenseStat() << endl;
      allPassed = false;
    }

    // Test healthStat setter
    p.setHealthStat(120);
    if (p.getHealthStat() != 120) {
      cout << "Health Stat setter test failed! Expected : 120 , Got : "
           << p.getHealthStat() << endl;
      allPassed = false;
    }

    if (allPassed) {
      cout << "Player Setters : All expected parameter tests passed!" << endl;
    }
  }
  void testSettersNegativeParameters() {
    TestPlayer p("Hero", "Sword", 30, 30, 100);
    bool allPassed = true;
    // Test attackStat setter
    p.setAttackStat(-70);
    if (p.getAttackStat() != 0) {
      cout << "Attack Stat setter test failed! Expected : -70 , Got : "
           << p.getAttackStat() << endl;
      allPassed = false;
    }

    // Test defenseStat setter
    p.setDefenseStat(-40);
    if (p.getDefenseStat() != 0) {
      cout << "Defense Stat setter test failed! Expected:-40 , Got: "
           << p.getDefenseStat() << endl;
      allPassed = false;
    }

    // Test healthStat setter
    p.setHealthStat(-120);
    if (p.getHealthStat() != 0) {
      cout << "Health Stat setter test failed! Expected: -120 , Got "
           << p.getHealthStat() << endl;
      allPassed = false;
    }

    p.setWeapon("Bow");
    if (p.getWeapon() != "Bow") {
      cout << "Weapon setter test failed! Expected: Bow , Got " << p.getWeapon()
           << endl;
      allPassed = false;
    }

    if (allPassed) {
      cout << "Player Setters : All negative parameter tests passed!" << endl;
    }
  }

  void testDefend() {
    bool allPassed = true;
    TestPlayer p("Hero", "Sword", 50, 30, 100);
    p.gameText = false;  // sets game text off for testing
    // case : player lives
    p.defend();        // sets isDefending = true
    p.takeDamage(40);  // should halve damage

    if (p.getHealthStat() != 80) {
      cout << "Defend test 1 failed! Expected : 80  , Got : "
           << p.getHealthStat() << "\n";
      allPassed = false;
    }

    // case: player dies
    p.defend();
    p.setHealthStat(100);  // set player health back to default
    p.takeDamage(1000);
    if (p.getHealthStat() != 0) {
      cout << "Defend test 2 failed! Expected : 0 , Got:" << p.getHealthStat()
           << "\n";
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
      cout << "Take damage test 1 failed! Expected : 90, Got "
           << p.getHealthStat() << "\n";
      allPassed = false;
    }

    // when attackStat = def
    p.setHealthStat(100);  // reset health
    p.takeDamage(30);

    if (p.getHealthStat() != 100) {
      cout << "Take damage test 2 failed! Expected : 100 , Got: "
           << p.getHealthStat() << "\n";
      allPassed = false;
    }

    // when attackStat < def
    p.setHealthStat(100);  // reset health
    p.takeDamage(0);

    if (p.getHealthStat() != 100) {
      cout << "Take damage test 3 failed! Expected: 100 , Got:"
           << p.getHealthStat() << "\n";
      allPassed = false;
    }

    // when attackStat is much greater than health
    p.takeDamage(1000);

    if (p.getHealthStat() != 0) {
      cout << "Take damage test 4 failed! Expected:0 , Got: "
           << p.getHealthStat() << "\n";
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
      cout << "Negative damage test  failed!Expected : 100 , Got :"
           << p.getHealthStat();
    }
    if (allPassed) {
      cout << "Negative damage tests passed!" << endl;
    }
  }
  void testBasicAttack() {
    bool allPassed = true;

    TestPlayer* attacker = new TestPlayer("Hero", "Sword", 50, 30, 100);
    TestPlayer* defender = new TestPlayer("Villain", "Axe", 40, 20, 100);

    attacker->gameText = false;  // suppress game text output
    defender->gameText = false;

    // attacker attacks defender with 25 damage
    attacker->basicAttack(defender, 25);

    // defender had 100 health, defense = 20 → takes (25 - 20) = 5 damage
    if (defender->getHealthStat() != 95) {
      cout << "BasicAttack test failed! Expected defender health = 95, Got = "
           << defender->getHealthStat() << endl;
      allPassed = false;
    }

    // reset health for next test
    defender->setHealthStat(100);

    // attacker attacks defender with 121 damage
    attacker->basicAttack(defender, 121);

    // defender had 100 health, defense = 20 → takes (121 - 20 ) = 101 damage,
    // hp should be 0 instead of -1
    if (defender->getHealthStat() != 0) {
      cout << "BasicAttack test failed! Expected defender health = 0, Got = "
           << defender->getHealthStat() << endl;
      allPassed = false;
    }

    if (allPassed) {
      cout << "Basic Attack tests passed!" << endl;
    }
    delete attacker;
    delete defender;
  }
  // Tests for Ranger Class
  void testRangerGetter() {
    Ranger r("abcd", "bow", 50, 30, 100);
    // dexterity is expected to equal = 1.5*50 = 75
    if (r.getDexterity() != 75) {
      cout << "Test failed , Expected : 100 , Got: " << r.getDexterity()
           << endl;

    } else {
      cout << "Ranger Getter tests passed!" << endl;
    }
  }
  void testBoostDex() {
    Ranger r("abcd", "bow", 50, 30, 100);
    r.gameText = false;
    bool allPassed = true;
    // test initial use , dexterity should be  1.5*50 + 30 = 105
    r.boostDex();
    if (r.getDexterity() != 105) {
      cout << "Test failed , Expected : 130 , Got: " << r.getDexterity()
           << endl;
      allPassed = false;
    }

    // test using all charges

    r.boostDex();  // dex should be 135
    r.boostDex();  // dex should be 165
    // expecting dexterity to be
    r.boostDex();
    if (r.getDexterity() != 165) {
      cout << "Test failed expected : 165, Got : " << r.getDexterity() << endl;
    }

    if (allPassed) {
      cout << "All boostDex tests passed!" << endl;
    }
  }
  void testRangerUltimate() {
    bool allPassed = true;
    Ranger r1("abcd", "bow", 50, 30, 100);
    Ranger* r2 = new Ranger("efgh", "bow", 50, 30, 1000);
    r1.gameText = false;
    r2->gameText = false;
    // Ultimate damage = 50*1.5 + (50*1.5)*0.8 = 135 , r2 hp should be
    // 1000+30-135 = 895
    r1.useUltimateSkill(r2);
    if (r2->getHealthStat() != 895) {
      cout << "Test failed, expected : 895, got: " << r2->getHealthStat()
           << endl;
    }
    // test if the ultimate counter works ,if it does work health should stay as
    // 895
    r1.useUltimateSkill(r2);
    if (r2->getHealthStat() != 895) {
      cout << "Test failed, expected : 895, got: " << r2->getHealthStat()
           << endl;
    }
    // When defend is active
    Ranger r3("abcd", "bow", 50, 30, 100);

    Ranger* r4 = new Ranger("efgh", "bow", 50, 30, 1000);
    r3.gameText = false;
    r4->gameText  = false;
    r4->defend();
    // Ultimate damage = 50*1.5 + (50*1.5)*0.8 = 135 , r2 hp should be 1000 -
    // 135/2 = 932.5
    r3.useUltimateSkill(r4);
    if (r4->getHealthStat() != 932.5) {
      cout << "Ultimate skill test failed , expected : 932.5 , got <<"
           << r4->getHealthStat() << endl;
    }
    if (allPassed) {
      cout << "All Ranger ultimate tests passed!" << endl;
    }
  }
};

#endif  // __UNITTESTS_H__