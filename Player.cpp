#include "Player.h"
// Paramaterised player constructor for testing purposes
Player::Player(string name, string weapon, int attackStat, int defenseStat,
               int healthStat) {
  this->name = name;
  this->weapon = weapon;
  this->attackStat = attackStat;
  this->defenseStat = defenseStat;
  this->healthStat = healthStat;
  isDefending = false;
  ultimateCounter = 3;
  useCounter = 1;
}
// Player class if player does not enter a name
Player::Player() {
  name = "Hero";
  weapon = "None";
  attackStat = 50;
  defenseStat = 30;
  healthStat = 1000;
  isDefending = false;
  ultimateCounter = 1;
  useCounter = 3;
}
// Player class if player enters a name
Player::Player(string name) {
  this->name = name;
  weapon = "None";
  attackStat = 50;
  defenseStat = 30;
  healthStat = 100;
  isDefending = false;
  ultimateCounter = 1;
  useCounter = 3;
}
string Player::getName() const { return name; }

string Player::getWeapon() const { return weapon; }

int Player::getAttackStat() const { return attackStat; }

int Player::getDefenseStat() const { return defenseStat; }

int Player::getHealthStat() const { return healthStat; }

void Player::setAttackStat(int attackStat) { this->attackStat = attackStat; }

void Player::setDefenseStat(int defenseStat) {
  this->defenseStat = defenseStat;
}

void Player::setHealthStat(int healthStat) { this->healthStat = healthStat; }

void Player::basicAttack(Action* entity, int damage) {
  entity->takeDamage(damage);
}

void Player::defend() { isDefending = true; }

void Player::takeDamage(int damage) {
  if (isDefending) {
    damage = damage / 2;
    healthStat = healthStat - damage;
    isDefending = false;

  } else {
    int damageTaken = damage - defenseStat;
    healthStat = healthStat - damageTaken;
  }
  if (healthStat < 0) {
    healthStat = 0;
  }
}
