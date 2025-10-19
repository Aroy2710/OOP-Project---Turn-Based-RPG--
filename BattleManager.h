#ifndef BATTLEMANAGER_H_
#define BATTLEMANAGER_H_

#include <iostream>
#include <string>

#include "Player.h"
#include "Enemy.h"

class BattleManager {

    public:

        BattleManager(Player* player, Enemy* enemy);
        ~BattleManager();

        void startBattle();
        void endBattle();
        void processTurn();
        void checkWinCondition();
        void getPlayerAction();

    private:

        Player* player;
        Enemy* enemy;
        bool isBattleActive;
        int turnCounter;
};

#endif  // BATTLEMANAGER_H_
