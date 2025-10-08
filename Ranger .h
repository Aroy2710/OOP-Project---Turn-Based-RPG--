#ifndef __RANGER_H__
#define __RANGER_H__
#include "Player.h"

class Ranger: public Player{
    public:
    Ranger() ;
    Ranger(string name);
    Ranger(string name, string weapon, float attackStat, float defenseStat,
         float healthStat);
    //getter
    float getDexterity();
    // method to recover dex for a set number of turns;
    void boostDex();
    void useUltimateSkill(Action* entity) override;
    ~Ranger();
    protected:
    int dexterity;
    

};




#endif // __RANGER_H__