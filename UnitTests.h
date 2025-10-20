#ifndef __UNITTESTS_H__
#define __UNITTESTS_H__
#include <sstream>
#include "Player.h"
#include "Ranger.h"
#include "Warrior.h"
#include "Mage.h"
#include "Barbarian.h"
#include "Swordsman.h"
#include "Archer.h"
#include "Gunner.h"
#include "Wizard.h"
#include "Warlock.h"
#include "BattleManager.h"
#include "Enemy.h"
#include "Orc.h"
#include "Goblin.h"
#include "GameManager.h"

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
  void useUltimateSkill(Entity* entity) override {
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
    testRangerUseBoost();
    testRangerUltimate();
    testWarriorGetter();
    testWarriorUseBoost();
    testWarriorUltimate();
    testMageGetter();
    testMageUseBoost();
    testMageUltimate();
    testArcherSpecialSkill();
    testGunnerSpecialSkill();
    testWizardSpecialSkill();
    testWarlockSpecialSkill();
    testBarbarianSpecialSkill();
    testSwordsmanSpecialSkill();
    testInventory();
  }
  void runEdgeCaseTests(){
    testOverkillDamage();
    testNegativeDamage();
    testNullTarget();
    testSkillReuseAfterDepletion();
    testSkillUseAfterDeath();
    
  }
  void testBattleManager() {
    
    Player* user = new Archer("Player", "Sword", 80, 50, 300);
    Orc* enemy = new Orc(70, 40, 250);
    BattleManager bm(user,enemy);
    bm.startBattle();

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

    attacker->basicAttack(defender);
    if (defender->getHealthStat() != 70) {
      cout << "BasicAttack test failed! Expected defender health: 95, Got: "
           << defender->getHealthStat() << endl;
      allPassed = false;
    }

    defender->setHealthStat(1);
    attacker->basicAttack(defender);
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
    r.gameText = false;
    if (r.getUniqueStat() != 75) {
      cout << "Test failed. Expected: 75, Got: " << r.getUniqueStat() << endl;
    } else {
      cout << "Ranger getter tests passed!" << endl;
    }
  }

  // Verifies that Ranger useBoost correctly increments dexterity with each use
  // and stops when all boost charges are used.
  void testRangerUseBoost() {
    bool allPassed = true;
    Ranger r("abcd", "bow", 50, 30, 100);
    r.gameText = false;

    r.useBoost();
    if (r.getUniqueStat() != 105) {
      cout << "Test failed. Expected: 105, Got: " << r.getUniqueStat() << endl;
      allPassed = false;
    }

    r.useBoost();
    r.useBoost();
    r.useBoost();
    if (r.getUniqueStat() != 165) {
      cout << "Test failed. Expected: 165, Got: " << r.getUniqueStat() << endl;
      allPassed = false;
    }

    if (allPassed) {
      cout << "All Ranger useBoost tests passed!" << endl;
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
    w.gameText = false;
    if (w.getUniqueStat() != 25) {
      cout << "Test failed. Expected: 25, Got: " << w.getUniqueStat() << endl;
    } else {
      cout << "Warrior getter tests passed!" << endl;
    }
  }

  // Verifies that Warrior boostStrength correctly increments strength with
  // each use and stops once charges are depleted.
  void testWarriorUseBoost() {
    bool allPassed = true;
    Warrior w("abcd", "club", 50, 30, 100);
    w.gameText = false;

    w.useBoost();
    if (w.getUniqueStat() != 55) {
      cout << "Test failed. Expected: 55, Got: " << w.getUniqueStat() << endl;
      allPassed = false;
    }

    w.useBoost();
    w.useBoost();
    w.useBoost();
    if (w.getUniqueStat() != 115) {
      cout << "Test failed. Expected: 115, Got: " << w.getUniqueStat() << endl;
      allPassed = false;
    }

    if (allPassed) {
      cout << "All Warrior useBoost tests passed!" << endl;
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
    m.gameText  = false;
    if (m.getUniqueStat() != 100) {
      cout << "Test failed. Expected: 100, Got: " << m.getUniqueStat() << endl;
    } else {
      cout << "Mage getter tests passed!" << endl;
    }
  }
  void testMageUseBoost() {
    bool allPassed = true;
    Mage m("abcd", "staff", 50, 30, 100);
    m.gameText = false;

    m.useBoost();
    if (m.getUniqueStat() != 130) {
      cout << "Test failed. Expected: 130, Got: " << m.getUniqueStat() << endl;
      allPassed = false;
    }

    m.useBoost(); // mana = 160
    m.useBoost(); // mana = 190
    m.useBoost(); // mana = 190
    if (m.getUniqueStat() != 190) {
      cout << "Test failed. Expected: 190, Got: " << m.getUniqueStat() << endl;
      allPassed = false;
    }

    if (allPassed) {
      cout << "All Mage useBoost tests passed!" << endl;
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
void testArcherSpecialSkill() {
  bool allPassed = true;
  Archer a1("abcd", "Bow", 50, 30, 100);
  Archer* a2 = new Archer("efgh", "Bow", 50, 30, 1000);
  a1.gameText = false;
  a2->gameText = false;

  // 1st use:
  // damage = 50 + 1.5*50 = 125
  // enemy hp = 1000 - (125 - 30) = 905
  a1.useSpecialSkill(a2);
  if (a2->getHealthStat() != 905) {
    cout << "Test 1 failed. Expected: 905, Got: " << a2->getHealthStat() << endl;
    allPassed = false;
  }

  // 2nd use:
  // attackStat = 60, dexterity = 1.5*60 = 90
  // damage = 60 + 90 = 150
  // enemy hp = 905 - (150 - 30) = 785
  a1.useSpecialSkill(a2);
  if (a2->getHealthStat() != 785) {
    cout << "Test 2 failed. Expected: 785, Got: " << a2->getHealthStat() << endl;
    allPassed = false;
  }

  // 3rd use:
  // attackStat = 70, dexterity = 1.5*70 = 105
  // damage = 70 + 105 = 175
  // enemy hp = 785 - (175 - 30) = 640
  a1.useSpecialSkill(a2);
  if (a2->getHealthStat() != 640) {
    cout << "Test 3 failed. Expected: 640, Got: " << a2->getHealthStat() << endl;
    allPassed = false;
  }

  // 4th use: should have NO EFFECT (counter depleted)
  float prevHealth = a2->getHealthStat();
  float prevAttack = a1.getAttackStat();
  a1.useSpecialSkill(a2);

  if (a2->getHealthStat() != prevHealth || a1.getAttackStat() != prevAttack) {
    cout << "Test 4 failed. Skill should have no effect when out of charges." << endl;
    cout << "Health before: " << prevHealth << ", after: " << a2->getHealthStat() << endl;
    cout << "Attack before: " << prevAttack << ", after: " << a1.getAttackStat() << endl;
    allPassed = false;
  }

  if (allPassed) {
    cout << "All Archer useSpecialSkill tests passed!" << endl;
  }

  delete a2;
}
void testGunnerSpecialSkill() {
    bool allPassed = true;
    Gunner g1("abcd", "Pistol", 50, 30, 100);
    Gunner* g2 = new Gunner("efgh", "Pistol", 50, 30, 1000);
    g1.gameText = false;
    g2->gameText = false;


    // 1st use:
    // damage = 3 * 50 = 150
    // enemy hp = 1000 -(150-30) = 850
    g1.useSpecialSkill(g2);
    if (g2->getHealthStat() != 880) {
        cout << "Test 1 failed. Expected: 880, Got: " << g2->getHealthStat() << endl;
        allPassed = false;
    }

    // 2nd use:
    // damage = 3 * 50 = 150 (attack stat not increased)
    // enemy hp = 880 - (150-30) = 770
    g1.useSpecialSkill(g2);
    if (g2->getHealthStat() != 760) {
        cout << "Test 2 failed. Expected: 760, Got: " << g2->getHealthStat() << endl;
        allPassed = false;
    }

    // 3rd use:
    // damage = 3 * 50 = 150
    // enemy hp = 760 - (150-30) = 640
    g1.useSpecialSkill(g2);
    if (g2->getHealthStat() != 640) {
        cout << "Test 3 failed. Expected: 640, Got: " << g2->getHealthStat() << endl;
        allPassed = false;
    }

    // 4th use: should have NO EFFECT (counter depleted)
    float prevHealth = g2->getHealthStat();
    float prevDefense = g1.getDefenseStat();
    g1.useSpecialSkill(g2);
    if (g2->getHealthStat() != prevHealth || g1.getDefenseStat() != prevDefense) {
        cout << "Test 4 failed. Skill should have no effect when out of charges." << endl;
        cout << "Health before: " << prevHealth << ", after: " << g2->getHealthStat() << endl;
        cout << "Defense before: " << prevDefense << ", after: " << g1.getDefenseStat() << endl;
        allPassed = false;
    }

    if (allPassed) {
        cout << "All Gunner useSpecialSkill tests passed!" << endl;
    }

    delete g2;
}
void testWizardSpecialSkill() {
    bool allPassed = true;

    Wizard w1("Mage1", "Staff", 50, 30, 200);
    Wizard* w2 = new Wizard("Mage2", "Staff", 50, 30, 1000);
    w1.gameText = false;
    w2->gameText = false;

    // 1st use:
    // damage = 2 * 100 = 200
    // enemy hp = 1000 - 200 + 30 -30  = 830
    w1.useSpecialSkill(w2);
    if (w2->getHealthStat() != 830) {
        cout << "Test 1 failed. Expected enemy HP: 830, Got: " << w2->getHealthStat() << endl;
        allPassed = false;
    }

    // 2nd use:
    // damage = 2 * 110 = 220
    // enemy hp = 830 - 220 + 30 = 640
    w1.useSpecialSkill(w2);
    if (w2->getHealthStat() != 640) {
        cout << "Test 2 failed. Expected enemy HP: 640, Got: " << w2->getHealthStat() << endl;
        allPassed = false;
    }

    // 3rd use:
    // damage = 2 * 120 = 240
    // enemy hp = 640 - 220 +30 = 430
    w1.useSpecialSkill(w2);
    if (w2->getHealthStat() != 430) {
        cout << "Test 3 failed. Expected enemy HP: 430, Got: " << w2->getHealthStat() << endl;
        allPassed = false;
    }

    // 4th use: should have NO EFFECT (counter depleted)
    float prevHP = w2->getHealthStat();
    float prevWizardHP = w1.getHealthStat();
    float prevMana = w1.getUniqueStat();
    w1.useSpecialSkill(w2);
    if (w2->getHealthStat() != prevHP || w1.getHealthStat() != prevWizardHP || w1.getUniqueStat() != prevMana) {
        cout << "Test 4 failed. Skill should have no effect when out of charges." << endl;
        cout << "Enemy HP before: " << prevHP << ", after: " << w2->getHealthStat() << endl;
        cout << "Wizard HP before: " << prevWizardHP << ", after: " << w1.getHealthStat() << endl;
        cout << "Wizard Mana before: " << prevMana << ", after: " << w1.getUniqueStat() << endl;
        allPassed = false;
    }

    if (allPassed) {
        cout << "All Wizard useSpecialSkill tests passed!" << endl;
    }

    delete w2;
}
void testWarlockSpecialSkill() {
    bool allPassed = true;

    Warlock w1("Lock1", "Staff", 50, 30, 200);
    Warlock* w2 = new Warlock("Lock2", "Staff", 50, 30, 1000);
    w1.gameText = false;
    w2->gameText = false;

    // 1st use:
    // raw damage = 0.25 * 200 = 50
    // actual damage = 50 - 30 = 20
    // enemy hp = 1000 - 20 = 980
    w1.useSpecialSkill(w2);
    if (w2->getHealthStat() != 980) {
        cout << "Test 1 failed. Expected enemy HP: 980, Got: " << w2->getHealthStat() << endl;
        allPassed = false;
    }

    // 2nd use:
    // Warlock health = 230, raw damage = 0.25 * 230 = 57.5
    // actual damage = 57.5 - 30 = 27.5
    // enemy hp = 980 - 27.5 = 952.5
    w1.useSpecialSkill(w2);
    if (w2->getHealthStat() != 952.5f) {
        cout << "Test 2 failed. Expected enemy HP: 952.5, Got: " << w2->getHealthStat() << endl;
        allPassed = false;
    }

    // 3rd use:
    // Warlock health = 260, raw damage = 0.25 * 260 = 65
    // actual damage = 65 - 30 = 35
    // enemy hp = 952.5 - 35 = 917.5
    w1.useSpecialSkill(w2);
    if (w2->getHealthStat() != 917.5f) {
        cout << "Test 3 failed. Expected enemy HP: 917.5, Got: " << w2->getHealthStat() << endl;
        allPassed = false;
    }

    // 4th use: should have NO EFFECT (counter depleted)
    float prevHP = w2->getHealthStat();
    float prevHealth = w1.getHealthStat();
    w1.useSpecialSkill(w2);
    if (w2->getHealthStat() != prevHP || w1.getHealthStat() != prevHealth) {
        cout << "Test 4 failed. Skill should have no effect when out of charges." << endl;
        cout << "Enemy HP before: " << prevHP << ", after: " << w2->getHealthStat() << endl;
        cout << "Warlock HP before: " << prevHealth << ", after: " << w1.getHealthStat() << endl;
        allPassed = false;
    }

    if (allPassed) {
        cout << "All Warlock useSpecialSkill tests passed!" << endl;
    }

    delete w2;
}
void testBarbarianSpecialSkill() {
    bool allPassed = true;

    Barbarian b1("Barb1", "Fist", 50, 30, 200);
    Barbarian* b2 = new Barbarian("Barb2", "Fist", 50, 30, 1000);
    b1.gameText = false;
    b2->gameText = false;

    // 1st use:
    // raw damage = 2*25 (strength) + 50 (attackStat) = 100
    // enemy hp = 1000 - (100 - 30) = 930
    b1.useSpecialSkill(b2);
    if (b2->getHealthStat() != 930) {
        cout << "Test 1 failed. Expected enemy HP: 930, Got: " << b2->getHealthStat() << endl;
        allPassed = false;
    }

    // 2nd use:
    // strength now = 35, damage = 2*35 + 50 = 120
    // enemy hp = 930 - (120 - 30) = 840
    b1.useSpecialSkill(b2);
    if (b2->getHealthStat() != 840) {
        cout << "Test 2 failed. Expected enemy HP: 840, Got: " << b2->getHealthStat() << endl;
        allPassed = false;
    }

    // 3rd use:
    // strength now = 45, damage = 2*45 + 50 = 140
    // enemy hp = 840 - (140 - 30) = 730
    b1.useSpecialSkill(b2);
    if (b2->getHealthStat() != 730) {
        cout << "Test 3 failed. Expected enemy HP: 730, Got: " << b2->getHealthStat() << endl;
        allPassed = false;
    }

    // 4th use: should have NO EFFECT (counter depleted)
    float prevHP = b2->getHealthStat();
    float prevStrength = b1.getUniqueStat();
    float prevDefense = b1.getDefenseStat();
    b1.useSpecialSkill(b2);
    if (b2->getHealthStat() != prevHP || b1.getUniqueStat() != prevStrength || b1.getDefenseStat() != prevDefense) {
        cout << "Test 4 failed. Skill should have no effect when out of charges." << endl;
        cout << "Enemy HP before: " << prevHP << ", after: " << b2->getHealthStat() << endl;
        cout << "Barbarian strength before: " << prevStrength << ", after: " << b1.getUniqueStat() << endl;
        cout << "Barbarian defense before: " << prevDefense << ", after: " << b1.getDefenseStat() << endl;
        allPassed = false;
    }

    if (allPassed) {
        cout << "All Barbarian useSpecialSkill tests passed!" << endl;
    }

    delete b2;
}
void testSwordsmanSpecialSkill() {
    bool allPassed = true;

    Swordsman s1("Sword1", "Sword", 50, 30, 200);
    Swordsman* s2 = new Swordsman("Sword2", "Sword", 50, 30, 1000);
    s1.gameText = false;
    s2->gameText = false;

    // 1st use:
    // strength = 25, damage = 5*25 + 50 = 175
    // enemy hp = 1000 - (175 - 30) = 855
    s1.useSpecialSkill(s2);
    if (s2->getHealthStat() != 855) {
        cout << "Test 1 failed. Expected enemy HP: 855, Got: " << s2->getHealthStat() << endl;
        allPassed = false;
    }

    // 2nd use:
    // strength = 35, damage = 5*35 + 50 = 225
    // enemy hp = 855 - (225 - 30) = 660
    s1.useSpecialSkill(s2);
    if (s2->getHealthStat() != 660) {
        cout << "Test 2 failed. Expected enemy HP: 660, Got: " << s2->getHealthStat() << endl;
        allPassed = false;
    }

    // 3rd use:
    // strength = 45, damage = 5*45 + 50 = 275
    // enemy hp = 660 - (275 - 30) = 415
    s1.useSpecialSkill(s2);
    if (s2->getHealthStat() != 415) {
        cout << "Test 3 failed. Expected enemy HP: 415, Got: " << s2->getHealthStat() << endl;
        allPassed = false;
    }

    // 4th use: should have NO EFFECT (counter depleted)
    float prevHP = s2->getHealthStat();
    float prevStrength = s1.getUniqueStat();
    float prevHealth = s1.getHealthStat();
    s1.useSpecialSkill(s2);
    if (s2->getHealthStat() != prevHP || s1.getUniqueStat() != prevStrength || s1.getHealthStat() != prevHealth) {
        cout << "Test 4 failed. Skill should have no effect when out of charges." << endl;
        cout << "Enemy HP before: " << prevHP << ", after: " << s2->getHealthStat() << endl;
        cout << "Swordsman strength before: " << prevStrength << ", after: " << s1.getUniqueStat() << endl;
        cout << "Swordsman health before: " << prevHealth << ", after: " << s1.getHealthStat() << endl;
        allPassed = false;
    }

    if (allPassed) {
        cout << "All Swordsman useSpecialSkill tests passed!" << endl;
    }

    delete s2;
  
}
void testInventory() {

  bool allPassed = true;
  TestPlayer p("Hero", "Sword", 50,30,1000);
  p.getInventory().setGameTextForAll(false);

  p.getInventory().use("Health Potion");
  if (p.getHealthStat() != 1200) {
    cout << "Inventory use test failed! Expected: 1200, Got: " << p.getHealthStat() << endl;
    allPassed = false;
  }

  if (allPassed) {
    cout << "All inventory tests passed!" << endl;
  }

}

// 1. HP cannot drop below zero
void testOverkillDamage() {
    TestPlayer p("Edge", "Sword", 50, 30, 100);
    p.gameText = false;
    p.takeDamage(1000);
    if (p.getHealthStat() == 0)
        cout << "testOverkillDamage passed!\n";
    else
        cout << "testOverkillDamage failed! Expected 0, got " << p.getHealthStat() << endl;
}
// 2. Negative damage shouldn't heal
void testNegativeDamage() {
    TestPlayer p("Edge", "Sword", 50, 30, 100);
    p.gameText = false;
    p.takeDamage(-100);
    if (p.getHealthStat() == 100)
        cout << "testNegativeDamage passed!\n";
    else
        cout << "testNegativeDamage failed! Expected 100, got " << p.getHealthStat() << endl;
}
// 3. Attacking a null target should not crash
void testNullTarget() {
    bool passed = true;
    try {
        TestPlayer attacker("Hero", "Sword", 50, 30, 100);
        attacker.gameText = false;
        attacker.basicAttack(nullptr);
    } catch (...) {
        passed = false;
    }
    cout << (passed ? "testNullTarget passed!\n" : "testNullTarget failed! Exception thrown.\n");
}
// 4. Using a skill after counter depletion should have no effect
void testSkillReuseAfterDepletion() {
    bool passed = true;
    Ranger r1("abc", "bow", 50, 30, 100);
    Ranger r2("xyz", "bow", 50, 30, 200);
    r1.gameText = false;
    r2.gameText = false;

    // use all 3 charges
    r1.useUltimateSkill(&r2);
    r1.useUltimateSkill(&r2);
    r1.useUltimateSkill(&r2);
    float prevHealth = r2.getHealthStat();
    r1.useUltimateSkill(&r2); // 4th time – should do nothing

    if (r2.getHealthStat() != prevHealth)
        passed = false;

    cout << (passed ? "testSkillReuseAfterDepletion passed!\n" : "testSkillReuseAfterDepletion failed!\n");
}

// 5. Skill use on dead player should have no effect
void testSkillUseAfterDeath() {
    bool passed = true;
    Ranger r1("Hero", "bow", 50, 30, 100);
    Ranger r2("Target", "bow", 50, 30, 10);
    r1.gameText = false;
    r2.gameText = false;

    r1.useUltimateSkill(&r2); // kills r2
    float prevHealth = r2.getHealthStat();
    r1.useUltimateSkill(&r2); // try again
    if (r2.getHealthStat() != prevHealth)
        passed = false;

    cout << (passed ? "testSkillUseAfterDeath passed!\n" : "testSkillUseAfterDeath failed!\n");
}



};

#endif  // __UNITTESTS_H__
