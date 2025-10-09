#include "Player.h"

// Parameterized constructor.
// Used for testing or initializing a Player with specific stats.
// By default, the player is not defending, can use the ultimate once,
// and can use special skills three times per battle.
Player::Player(std::string name, std::string weapon, float attack_stat,
               float defense_stat, float health_stat)
    : name(name),
      weapon(weapon),
      attackStat(attack_stat),
      defenseStat(defense_stat),
      healthStat(health_stat),
      maxHealth(health_stat),
      isDefending(false),
      ultimateCounter(1),
      useCounter(3) {}

// Default constructor.
// Initializes a Player with generic "Hero" attributes and default stats.
Player::Player()
    : name("Hero"),
      weapon("None"),
      attackStat(50.0f),
      defenseStat(30.0f),
      healthStat(1000.0f),
      maxHealth(1000.0f),
      isDefending(false),
      ultimateCounter(1),
      useCounter(3) {}

// Constructor for Player with a custom name but default stats.
Player::Player(std::string name)
    : name(name),
      weapon("None"),
      attackStat(50.0f),
      defenseStat(30.0f),
      healthStat(1000.0f),
      maxHealth(1000.0f),
      isDefending(false),
      ultimateCounter(1),
      useCounter(3) {}

// Getter methods.
std::string Player::getName() const { return name; }

std::string Player::getWeapon() const { return weapon; }

float Player::getAttackStat() const { return attackStat; }

float Player::getDefenseStat() const { return defenseStat; }

float Player::getHealthStat() const { return healthStat; }

// Setter methods with input validation.
void Player::setAttackStat(float attack_stat) {
  attackStat = attack_stat < 0.0f ? 0.0f : attack_stat;
}

void Player::setDefenseStat(float defense_stat) {
  defenseStat = defense_stat < 0.0f ? 0.0f : defense_stat;
}

void Player::setHealthStat(float health_stat) {
  healthStat = health_stat < 0.0f ? 0.0f : health_stat;
}

void Player::setWeapon(std::string weapon_name) {
  weapon = weapon_name;
}

// Executes a basic attack on another entity.
// The entity takes damage based on the Player's attack value.
void Player::basicAttack(Action* entity, float damage) {
  if (gameText) {
    std::cout << name << " is now attacking." << std::endl;
  }
  entity->takeDamage(damage);
}

// Sets the player to a defending state for the next turn.
void Player::defend() {
  isDefending = true;
}

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
      std::cout << name << " has taken " << damage << " damage." << std::endl;
      std::cout << "Health of " << name << ": " << healthStat << std::endl;
      std::cout << name << " is no longer defending." << std::endl;
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
      std::cout << name << " has taken " << damage << " damage." << std::endl;
      std::cout << "Health of " << name << ": " << healthStat << std::endl;
    }
  }

  // Clamp health to a minimum of zero.
  if (healthStat < 0.0f) {
    healthStat = 0.0f;
  }
}
