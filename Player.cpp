#include "Player.h"

Player::Player(string name,string weapon,int attackStat,int defenseStat, int healthStat)
{
    this->name = name;
    this->weapon = weapon;
    this->attackStat = attackStat;
    this->defenseStat = defenseStat;
    this->healthStat = healthStat;
    
}
string Player::getName()
{
    return name;
    
}

string Player::getWeapon()
{
    return weapon;
    
}

int Player::getAttackStat()
{
    return attackStat;
    
}

int Player::getDefenseStat()
{
    return defenseStat;
    
}

int Player::getHealthStat()
{
    return healthStat;
    
}

void Player::setAttackStat(int attackStat)
{
    this->attackStat =attackStat;
    
}

void Player::setDefenseStat(int defenseStat)
{
    this->defenseStat = defenseStat;
    
}

void Player::setHealthStat(int healthStat)
{
    this->healthStat = healthStat;
    
}

void Player::basicAttack(Action* entity, int damage)
{
    
}

void Player::defend()
{
    
}


void Player::takeDamage(int damage)
{
    
}


