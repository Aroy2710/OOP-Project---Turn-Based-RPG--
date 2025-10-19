#include "Goblin.h"
#include "Goblin.h"


using namespace std;

// Default constructor.
// Initializes a Goblin with default Enemy stats.
Goblin::Goblin() : Enemy() {
  typeName = "Goblin";
}

// Parameterized constructor.
// Initializes a Goblin with specific stats.
Goblin::Goblin(float attackStat, float defenseStat, float healthStat)
    : Enemy(attackStat, defenseStat, healthStat) {
  typeName = "Goblin";
}

// Special attack: Bleed Damage.
// Deals enhanced damage and increases the Goblin's attack stat.
void Goblin::useSpecialSkill(Action* target) {
  float damage = attackStat * 1.3f + (damageBoost ? extraDamage : 0);
  attackStat += 10.0f;

  if (gameText) {
    cout << typeName << " uses Bleed Damage!" << endl;
  }

  target->takeDamage(damage);
}

// Defines the Goblin's behavior during its turn.
void Goblin::performTurn(Action* target) {
  int r = rand() % 100;  // Random number between 0-99

  if (damageBoost) {
    // When in damage boost mode, only use basic attacks or Bleed Damage
    if (r < 50) {
      basicAttack(target);
      extraDamage += 2;  // Increase extraDamage per attack
    } else {
      useSpecialSkill(target);
      extraDamage += 2;
    }

  } else {
    // Normal behavior
    if (r < 65) {
      basicAttack(target);
      if (damageBoost) extraDamage += 2;

    } else if (r < 95) {
      defend();

    } else {
      useSpecialSkill(target);
      if (damageBoost) extraDamage += 2;
    }
  }
}
// Basic attack specifically for goblin
void Goblin::basicAttack(Action* target) {
  float damage;
  if (damageBoost){
    damage = attackStat + extraDamage;
    
    
  }
  else{
    damage = attackStat;
  }
  
  if (!target) {
    if (gameText) cout << typeName << " tried to attack, but there's no target!\n";
    return;
  }
  if (gameText) cout << typeName << " attacks." << endl;
  target->takeDamage(damage);
}


// Triggered when Goblin HP is low.
// Enables damage boost and prints message.
void Goblin::onLowHP() {
  if (gameText) {
    cout << typeName
         << " becomes desperate! Gains damage per attack!" << endl;
  }

  damageBoost = true;
}
