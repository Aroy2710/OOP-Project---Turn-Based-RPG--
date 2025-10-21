#ifndef BATTLEMANAGER_H_
#define BATTLEMANAGER_H_

#include <iostream>
#include <string>

#include "Player.h"
#include "Enemy.h"

class BattleManager {

    public:

        int turnCounter;

        BattleManager(Player* player, Enemy* enemy);
        BattleManager(Player* player, Enemy* enemy, string saveFileName);
        ~BattleManager();

        void startBattle();
        void endBattle();
        void processTurn();
        void checkWinCondition();
        void getPlayerAction();
        void saveGame();
        int getTurnCounter(void);

    private:

        Player* player;
        Enemy* enemy;
        bool isBattleActive;
        string saveFileName;
};

#endif  // BATTLEMANAGER_H_
