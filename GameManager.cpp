#include "GameManager.h"

GameManager::GameManager() {
    showMainMenu();
    saveFileExists = false;
}

GameManager::~GameManager() {
    delete player;
    delete enemy;
    delete currentBattle;
}

void GameManager::startNewGame() {
    cout << "Please enter your character's name: ";
    string playerName;
    cin.ignore();
    getline(cin, playerName);
    
    bool validChoice = true;
    int archetypeChoice;
    do {
        cout << "Choose your archetype:\n1. Warrior\n2. Mage\n3. Ranger\n";
        cout << "Enter the number of your choice: ";
        cin >> archetypeChoice;

        if (archetypeChoice < 1 || archetypeChoice > 3) {
            cout << "Invalid choice. Please choose a valid archetype.\n";
            validChoice = false;
            continue;
        }

    } while (!validChoice);

    validChoice = true;
    int classType;

    do {
        if (archetypeChoice == 1) {
            cout << "Please choose your warrior type:\n1. Swordsman\n2. Barbarian\n";
            cout << "Enter the number of your choice: ";
            cin >> classType;

            if (classType == 1) {
                player = new Swordsman(playerName);
            } else if (classType == 2) {
                player = new Barbarian(playerName);
            } else {
                cout << "Invalid choice. Please choose a valid warrior type.\n";
                validChoice = false;
                continue;
            }
        } else if (archetypeChoice == 2) {
            cout << "Please choose your mage type:\n1. Wizard\n2. Warlock\n";
            cout << "Enter the number of your choice: ";
            cin >> classType;

            if (classType == 1) {
                player = new Wizard(playerName);
            } else if (classType == 2) {
                player = new Warlock(playerName);
            } else {
                cout << "Invalid choice. Please choose a valid mage type.\n";
                validChoice = false;
                continue;
            }
        } else if (archetypeChoice == 3) {
            cout << "Please choose your ranger type:\n1. Archer\n2. Gunner\n";
            cout << "Enter the number of your choice: ";
            cin >> classType;

            if (classType == 1) {
                player = new Archer(playerName);
            } else if (classType == 2) {
                player = new Gunner(playerName);
            } else {
                cout << "Invalid choice. Please choose a valid ranger type.\n";
                validChoice = false;
                continue;
            }
        }
    } while (!validChoice);
    
    cout << "Character created successfully! Welcome, " << player->getName() << "!\n";

    cout << "Please choose an enemy to battle:\n1. Goblin\n2. Orc\n3. Human\n";
    cout << "Enter the number of your choice: ";
    int enemyChoice;

    do {
        cin >> enemyChoice;

        if (enemyChoice == 1) {
            enemy = new Goblin();
            validChoice = true;
        } else if (enemyChoice == 2) {
            enemy = new Orc();
            validChoice = true;
        } else if (enemyChoice == 3) {
            enemy = new Human();
            validChoice = true;
        } else {
            cout << "Invalid choice. Please choose a valid enemy.\n";
            validChoice = false;
        }
    } while (!validChoice);

    cout << "Please enter a save file name (default: savegame.dat): ";
    cin >> saveFileName;

    system("clear");

    currentBattle = new BattleManager(player, enemy);

    currentBattle->startBattle();
}

void GameManager::showMainMenu() {
    cout << "Welcome to the Turn-Based RPG!" << endl;
    cout << "1. Start New Game" << endl;
    cout << "2. Load Game" << endl;
    cout << "3. Quit" << endl;

    int choice;
    bool validChoice = true;

    do {
        cout << "Enter the number of your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                startNewGame();
                break;
            case 2:
                loadGame();
                break;
            case 3:
                quitGame();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                validChoice = false;
                break;
        }
    } while (!validChoice);
}

void GameManager::loadGame() {
    cout << "Load game functionality not yet implemented." << endl;
}

void GameManager::saveGame() {
    cout << "Save game functionality not yet implemented." << endl;
}

void GameManager::quitGame() {
    saveGame();
    cout << "Thank you for playing! Goodbye." << endl;
    exit(0);
}