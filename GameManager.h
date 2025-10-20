#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

#include "Player.h"
#include "Ranger.h"
#include "Warrior.h"
#include "Mage.h"
#include "Barbarian.h"
#include "Swordsman.h"
#include "Archer.h"
#include "Gunner.h"
#include "Wizard.h"
#include "Warlock.h"
#include "BattleManager.h"
#include "Enemy.h"
#include "Orc.h"
#include "Goblin.h"
#include "Human.h"

class GameManager {

    public:
    
        GameManager();
        ~GameManager();

        void startNewGame();
        void showMainMenu();
        void loadGame();
        void saveGame();
        void quitGame();
        void showBattleResults();

    private:
        Player* player;
        Enemy* enemy;
        BattleManager* currentBattle;
        string saveFileName;
        bool saveFileExists;

};
#endif // __GAMEMANAGER_H__