#include <cstdlib>
#include <unistd.h>
#include <limits>
#include <iomanip>

#include "BattleManager.h"

BattleManager::BattleManager(Player* player, Enemy* enemy) {
    this->player = player;
    this->enemy = enemy;
    isBattleActive = false;
    turnCounter = 0;
}

BattleManager::~BattleManager() = default;

void BattleManager::startBattle() {
    isBattleActive = true;
    turnCounter = 1;
    std::cout << "Battle started between " << player->getName() << " and " << enemy->getTypeName() << "!" << std::endl;

    while (isBattleActive) {
        processTurn();
    }

}

void BattleManager::processTurn() {
    if (!isBattleActive) {
        std::cout << "No active battle to process." << std::endl;
        return;
    }
    cout << "Turn " << turnCounter << " begins!\n";

    cout << left
        << setw(18) << "Player HP:"      << right << setw(6) << player->getHealthStat()
        << "   |   "
        << left << setw(18) << "Enemy HP:"      << right << setw(6) << enemy->getHealthStat() << '\n';

    cout << left
        << setw(18) << "Player Attack:"  << right << setw(6) << player->getAttackStat()
        << "   |   "
        << left << setw(18) << "Enemy Attack:"  << right << setw(6) << enemy->getAttackStat() << '\n';

    cout << left
        << setw(18) << "Player Defense:" << right << setw(6) << player->getDefenseStat()
        << "   |   "
        << left << setw(18) << "Enemy Defense:" << right << setw(6) << enemy->getDefenseStat() << '\n';

    // Polymorphic unique stat — the derived class prints its own label (e.g. "Player Mana :")
    cout << left;
     // prints "Player Mana :" or similar
    cout << setw(8) << right << player->getUniqueStat() <<   // show numeric value aligned
         "   |" << endl;

    cout<<endl;

    cout << "----------------------------------------" << endl;
    cout << "Skills/Items available:" << endl;
    cout << "Ultimate Skill Charges: " << player->getUltimateCounter() << endl;
    cout << "Boost Charges: " << player->getBoostCounter() << endl;
    cout << "Special Skill Charges: " << player->getSpecialSkillCounter() << endl;
    cout << "----------------------------------------" << endl;
    cout << "Items in Inventory:" << endl;
    cout << player->getInventory().listItems();
    cout << "----------------------------------------" << endl;

    cout << "Player's turn:" << endl;
    getPlayerAction();
    sleep(2);
    cout << endl;

    cout << "Enemy's turn:" << endl;
    enemy->performTurn(player);
    sleep(3);
    

    checkWinCondition();
    turnCounter++;
}

void BattleManager::getPlayerAction() {

    cout << "Choose an action for " << player->getName() << ":" << std::endl;
    cout << "1. Basic Attack" << endl;
    cout << "2. Defend" << endl;
    cout << "3. Use special skill" << endl;
    cout << "4. Use boost" << endl;
    cout << "5. Use ultimate skill" << endl;
    cout << "6. Use item" << endl;


    bool validCommand = false;

    do {
        cout << "Enter the number of your choice: ";
        validCommand = true;

        int command;

        while (!(cin >> command)) {
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 6." << endl;
            cout << "Enter the number of your choice: ";
            continue;
        }
        cout << endl;

        switch (command)
        {
        case 1:
            player->basicAttack(enemy);
            break;
        case 2:
            // Defend
            player->defend();
            break;
        case 3:
            // Use special skill
            player->useSpecialSkill(enemy);
            break;
        case 4:
            // Use boost
            if (player->getBoostCounter() <= 0) {
                cout << "No boost charges left!" << endl;
                validCommand = false;
                break;
            }
            player->useBoost();
            break;
        case 5:
            // Use ultimate skill
            if (player->getUltimateCounter() <= 0 || turnCounter < 2) {
                cout << "Ultimate skill not available!" << endl;
                validCommand = false;
                break;
            }
            player->useUltimateSkill(enemy);
            break;
        case 6:
            // Use item
            {

                if (player->getInventory().listItems() == "Empty\n") {
                    cout << "No items available in inventory!" << endl;
                    validCommand = false;
                    break;
                }

                bool validItem = false;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                do {
                    string chosenItem = "";
                    cout << "Inventory items:\n" << player->getInventory().listItems() << endl;
                    cout << "Enter the name of the item to use: ";
                    std::getline(std::cin, chosenItem);

                    try {
                        player->getInventory().use(chosenItem);
                        validItem = true;
                    }
                    catch (const std::exception& e) {
                        cout << "Item \"" << chosenItem << "\" not found or could not be used: " << e.what() << endl;
                        cout << "Please enter a valid item.\n\n";
                    }
                    catch (...) {
                        cout << "Unknown error using item \"" << chosenItem << "\".\n";
                        cout << "Please try again.\n\n";
                    }
                
                } while (!validItem); // only repeats this case if invalid
            }
            break;
        
        default:
            // Invalid choice
            cout << "Not sure how you got here, turn skipped" << endl;
            break;
        }
    } while (!validCommand);

}

void BattleManager::checkWinCondition() {
    if (player->getHealthStat() <= 0) {
        std::cout << player->getName() << " has been defeated! Game Over." << std::endl;
        endBattle();
    } else if (enemy->getHealthStat() <= 0) {
        std::cout << enemy->getTypeName() << " has been defeated! You win!" << std::endl;
        endBattle();
    }
}

void BattleManager::endBattle() {
    isBattleActive = false;
}