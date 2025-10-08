#ifndef __WARRIOR_H__
#define __WARRIOR_H__


#include "Player.h"

class Warrior: public Player{
    public:
    Warrior() ;
    Warrior(string name);
    Warrior(string name, string weapon, float attackStat, float defenseStat,
         float healthStat);
    //getter
    float getStrength();
    // method to recover dex for a set number of turns;
    void boostStrength();
    void useUltimateSkill(Action* entity) override;
    ~Warrior();
    protected:
    float strength;
    

};





#endif // __WARRIOR_H__