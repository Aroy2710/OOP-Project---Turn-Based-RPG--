#include "Player.h"
// Paramaterised player constructor for testing purposes
// at the start of the game player will not be defending
// player can only use ultimate skills once
// player can use their special skills only 3 times in battle
Player::Player(string name, string weapon, int attackStat, int defenseStat,
               int healthStat) {
  this->name = name;
  this->weapon = weapon;
  this->attackStat = attackStat;
  this->defenseStat = defenseStat;
  this->healthStat = healthStat;

  isDefending = false;

  ultimateCounter = 1;

  useCounter = 3;
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
  healthStat = 1000;
  isDefending = false;
  ultimateCounter = 1;
  useCounter = 3;
}
// Getter methods
string Player::getName() const { return name; }

string Player::getWeapon() const { return weapon; }

int Player::getAttackStat() const { return attackStat; }

int Player::getDefenseStat() const { return defenseStat; }

int Player::getHealthStat() const { return healthStat; }

// Setter Methods

void Player::setAttackStat(int attackStat) {
  if (attackStat < 0) {
    this->attackStat = 0;
  } else {
    this->attackStat = attackStat;
  }
}

void Player::setDefenseStat(int defenseStat) {
  if (defenseStat < 0) {
    this->defenseStat = 0;
  } else {
    this->defenseStat = defenseStat;
  }
}

void Player::setHealthStat(int healthStat) {
  if (healthStat < 0) {
    this->healthStat = 0;
  } else {
    this->healthStat = healthStat;
  }
}

void Player::basicAttack(Action* entity, int damage) {
  // if player chooses to attack using their weapon , then the enemy takes
  // damage
  cout << name << " is now attacking" << endl;
  entity->takeDamage(damage);
}

// Defend option during battle

void Player::defend() { isDefending = true; }

// Method for player and enemy to take damage , calculation differs whether
// player is defending or not
void Player::takeDamage(int damage) {
  // if the player is defending , defense stat is not taken into consideration,
  // damage is strictly halved
  if(damage<0){
    damage = 0;
  }
  if (isDefending) {
    damage = damage / 2;

    healthStat = healthStat - damage;
    if (gameText) {
      cout << name << " has taken " << damage << " damage" << endl;
      cout << "Health of " << name << " : " << healthStat << endl;
      cout << name << " is no longer defending" << endl;
    }
    if (healthStat < 0) {
      healthStat = 0;
    }

    isDefending = false;

  }
  // if the player is not defending, defense stat is taken into consideration
  else {
    damage = damage - defenseStat;
    if (damage < 0) {
      damage = 0;
    }
    healthStat = healthStat - damage;

    if (gameText) {
      cout << name << " has taken " << damage << "damage" << endl;
      cout << "Health of " << name << " " << healthStat << endl;
    }
  }
  // sets health to 0
  if (healthStat < 0) {
    healthStat = 0;
  }
}
