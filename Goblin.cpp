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
void Goblin::useSpecialSkill(Entity* target) {
  float damage = attackStat * 1.3f + (damageBoost ? extraDamage : 0);
  attackStat += 10.0f;

  if (gameText) {
    cout << typeName << " uses Bleed Damage!" << endl;
  }

  target->takeDamage(damage);
}

// Defines the Goblin's behavior during its turn.
void Goblin::performTurn(Entity* target) {
  // Generate a random number from 0 to 99.
  // Create a static random generator once (not every turn)
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(0, 99);
  int randomAction = dist(gen);  // truly random in [0, 99]

  if (damageBoost) {
    // When in damage boost mode, only use basic attacks or Bleed Damage
    if (randomAction < 50) {
      basicAttack(target);
      extraDamage += 2;  // Increase extraDamage per attack
    } else {
      useSpecialSkill(target);
      extraDamage += 2;
    }

  } else {
    // Normal behavior
    if (randomAction < 65) {
      basicAttack(target);
      if (damageBoost) extraDamage += 2;

    } else if (randomAction < 95) {
      defend();

    } else {
      useSpecialSkill(target);
    }
  }
}
// Basic attack specifically for goblin
void Goblin::basicAttack(Entity* target) {
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
