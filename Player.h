#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "Action.h"
#include <iostream>
using namespace std;

class Player: public Action{
    public:
    Player(string name,string weapon,int attackStat,int defenseStat, int healthStat);
    string getName() const;
    string getWeapon() const;
    int getAttackStat() const;
    int getDefenseStat() const;
    int getHealthStat() const;
    void setAttackStat(int attackStat);
    void setDefenseStat(int defenseStat);
    void setHealthStat(int healthStat);
    virtual void useUltimateSkill(Action* entity) = 0;
    void basicAttack(Action* entity, int damage) override;
    void defend() override;
    void takeDamage(int damage) override;
    virtual ~Player() = default;

    protected:
    string name;
    string weapon;
    int attackStat;
    int defenseStat;
    bool isDefending;
    int healthStat;
    int ultimateCounter;
    int useCounter;
    

};

#endif // __PLAYER_H__