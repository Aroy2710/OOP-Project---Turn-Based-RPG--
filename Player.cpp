#include "Player.h"

using namespace std;

// Parameterized constructor.
// Initializes a Player with specific stats.
// By default, the player is not defending, can use the ultimate once,
// and can use special skills three times per battle.
Player::Player(string name, string weapon, float attackStat,
               float defenseStat, float healthStat) : inventory(this) {
  this->name = name;
  this->weapon = weapon;
  this->attackStat = attackStat;
  this->defenseStat = defenseStat;
  this->healthStat = healthStat;
  maxHealth = healthStat;
  isDefending = false;
  ultimateCounter = 1;
  boostCounter = 3;
  specialSkillCounter = 3;
}

// Default constructor.
// Initializes a Player with generic "Hero" attributes.
Player::Player() : inventory(this) {
  name = "Hero";
  weapon = "None";
  attackStat = 50.0f;
  defenseStat = 30.0f;
  healthStat = 1000.0f;
  maxHealth = 1000.0f;
  isDefending = false;
  archetype = "";
  ultimateCounter = 1;
  boostCounter = 3;
  specialSkillCounter = 3;
}

// Constructor with custom name but default stats.
Player::Player(string name) : inventory(this) {
  this->name = name;
  weapon = "None";
  attackStat = 50.0f;
  defenseStat = 30.0f;
  healthStat = 1000.0f;
  maxHealth = 1000.0f;
  isDefending = false;
  archetype = "";
  ultimateCounter = 1;
  boostCounter = 3;
  specialSkillCounter = 3;
}

// Getter methods
string Player::getName() const { return name; }

string Player::getWeapon() const { return weapon; }

float Player::getAttackStat() const { return attackStat; }

float Player::getDefenseStat() const { return defenseStat; }

float Player::getHealthStat() const { return healthStat; }

int   Player::getBoostCounter() const { return boostCounter; }

int Player::getUltimateCounter() const { return ultimateCounter; }

int Player::getSpecialSkillCounter() const { return specialSkillCounter; }

Inventory& Player::getInventory() { return inventory; }

// Setter methods with validation
void Player::setAttackStat(float attackStat) {
  this->attackStat = attackStat < 0.0f ? 0.0f : attackStat;
}

void Player::setDefenseStat(float defenseStat) {
  this->defenseStat = defenseStat < 0.0f ? 0.0f : defenseStat;
}

void Player::setHealthStat(float healthStat) {
  this->healthStat = healthStat < 0.0f ? 0.0f : healthStat;
}

void Player::setWeapon(string weapon) { this->weapon = weapon; }

// Executes a basic attack on another entity.
// The entity takes damage based on the Player's attack value.
void Player::basicAttack(Action* entity) {
  float damage = attackStat;
  if (!entity) {
    if (gameText) std::cout << name << " tried to attack, but there's no target!\n";
    return;
  }
  if (gameText) {
    cout << name << " is now attacking with their " << weapon << endl;
  }
  entity->takeDamage(damage);
}

// Sets the player to a defending state for the next turn.
void Player::defend() { isDefending = true; }

// Handles how the Player takes damage during battle.
// - If defending: damage is halved.
// - If not defending: defense stat reduces incoming damage.
// Health is clamped to zero to avoid negative values.
void Player::takeDamage(float damage) {
  if (damage < 0.0f) {
    damage = 0.0f;
  }

  if (isDefending) {
    // Defending halves all incoming damage.
    damage *= 0.5f;
    healthStat -= damage;

    if (gameText) {
      cout << name << " has taken " << damage << " damage." << endl;
      cout << name << " is no longer defending." << endl;
    }

    isDefending = false;

  } else {
    // Non-defending damage is reduced by the defense stat.
    damage -= defenseStat;
    if (damage < 0.0f) {
      damage = 0.0f;
    }

    healthStat -= damage;

    if (gameText) {
      cout << name << " has taken " << damage << " damage." << endl;
    }
  }

  // Clamp health to zero.
  if (healthStat < 0.0f) {
    healthStat = 0.0f;
  }
}

void Player::useBoost()
{
  
}


void Player::useSpecialSkill(Action* entity)
{
  (void)entity;  // suppress unused warning
  
}
