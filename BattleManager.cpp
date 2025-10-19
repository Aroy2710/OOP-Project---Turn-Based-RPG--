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
}

void BattleManager::processTurn() {
    if (!isBattleActive) {
        std::cout << "No active battle to process." << std::endl;
        return;
    }

    std::cout << "Turn " << turnCounter << " begins!" << std::endl;

    cout << "Player HP: " << player->getHealthStat() << " | Enemy HP: " << enemy->getHealthStat() << endl;
    cout << "Player Attack: " << player->getAttackStat() << " | Enemy Attack: " << enemy->getAttackStat() << endl;
    cout << "Player Defense: " << player->getDefenseStat() << " | Enemy Defense: " << enemy->getDefenseStat() << endl;
    cout << "----------------------------------------" << endl;
    cout << "Skills/Items available:" << endl;
    cout << "Ultimate Skill Charges: " << player->getUltimateCounter() << endl;
    cout << "Boost Charges: " << player->getBoostCounter() << endl;
    cout << "Special Skill Charges: " << player->getSpecialSkillCounter() << endl;
    cout << "----------------------------------------" << endl;
    cout << "Items in Inventory:" << endl;
    cout << player->getInventory().listItems() << endl;
    cout << "----------------------------------------" << endl;

    cout << "Player's turn:" << endl;
    getPlayerAction();

    cout << "Enemy's turn:" << endl;
    enemy->performTurn(player);

    checkWinCondition();
    turnCounter++;
}

void BattleManager::getPlayerAction() {
    
    int choice;

    cout << "Choose an action for " << player->getName() << ":" << std::endl;
    cout << "1. Basic Attack" << endl;
    cout << "2. Defend" << endl;
    cout << "3. Use special skill" << endl;
    cout << "4. Use boost" << endl;
    cout << "5. Use ultimate skill" << endl;
    cout << "6. Use item" << endl;
    cout << "Enter the number of your choice: ";

    

    // Read and validate choice (must be integer 1-6)
    while (true) {
        
        cin >> choice;

        if (choice < 1 || choice > 6) {
            cout << "Choice out of range. Please enter a number between 1 and 6: ";
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore(10000, '\n'); // consume remaining input on the line
        break;
    }
    cout << endl;

    switch (choice)
    {
    case 1:
        cout << player->getName() << " attacks " << enemy->getTypeName() << "!" << endl;
        player->basicAttack(enemy, player->getAttackStat());
        break;
    case 2:
        // Defend
        cout << player->getName() << " is defending this turn!" << endl;
        player->defend();
        break;
    case 3:
        // Use special skill
        break;
    case 4:
        // Use boost
        
        break;
    case 5:
        // Use ultimate skill
        if (player->getUltimateCounter() <= 0) {
            cout << "Ultimate skill not available!" << endl;
            break;
        }
        cout << player->getName() << " uses their ultimate skill!" << endl;
        player->useUltimateSkill(enemy);
        break;
    case 6:
        // Use item
        {
            string chosenItem = "";
            cout << "Inventory items:\n" << player->getInventory().listItems();
            cout << "Enter the name of the item to use: ";
            cin >> chosenItem;
            player->getInventory().use(chosenItem);
        }
        break;
    default:
        // Invalid choice
        cout << "Not sure how you got here, turn skipped" << endl;
        break;
    }

}