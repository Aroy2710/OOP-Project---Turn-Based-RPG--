#include <cstdlib>
#include <unistd.h>
#include <limits>
#include <iomanip>
#include <fstream>

#include "BattleManager.h"
#include "GameManager.h"

using namespace std;

// Constructs a BattleManager with a player and an enemy.
BattleManager::BattleManager(Player* player, Enemy* enemy) {
  this->player = player;
  this->enemy = enemy;
  isBattleActive = false;
  turnCounter = 1;
}

BattleManager::BattleManager(Player* player, Enemy* enemy, string saveFileName) {
  this->player = player;
  this->enemy = enemy;
  this->saveFileName = saveFileName;
  isBattleActive = false;
  turnCounter = 1;
}

BattleManager::~BattleManager() = default;

// Starts a new battle sequence between the player and enemy.
void BattleManager::startBattle() {
  isBattleActive = true;
  turnCounter = getTurnCounter();

  cout << "Battle started between " << player->getName() << " and "
       << enemy->getTypeName() << "!" << endl;

  while (isBattleActive) {
    processTurn();
  }
}

// Processes a single battle turn.
void BattleManager::processTurn() {
  checkWinCondition();
  if (!isBattleActive) {
    cout << "No active battle to process." << endl;
    return;
  }

  cout << "Turn " << turnCounter << " begins!\n";

  cout << left
       << setw(18) << "Player HP:" << right << setw(6) << player->getHealthStat()
       << "   |   " << left << setw(18) << "Enemy HP:" << right << setw(6)
       << enemy->getHealthStat() << '\n';

  cout << left << setw(18) << "Player Attack:" << right << setw(6)
       << player->getAttackStat() << "   |   " << left << setw(18)
       << "Enemy Attack:" << right << setw(6) << enemy->getAttackStat() << '\n';

  cout << left << setw(18) << "Player Defense:" << right << setw(6)
       << player->getDefenseStat() << "   |   " << left << setw(18)
       << "Enemy Defense:" << right << setw(6) << enemy->getDefenseStat()
       << '\n';

  // Polymorphic unique stat (e.g., "Player Mana :").
  cout << left;
  cout << setw(8) << right << player->getUniqueStat() << "   |" << endl;

  cout << endl;
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

  checkWinCondition();

  cout << "Enemy's turn:" << endl;
  enemy->performTurn(player);
  sleep(3);

  // Check victory or defeat at the end of the turn.
  checkWinCondition();
  turnCounter++;
}

// Prompts the player to select an action each turn.
void BattleManager::getPlayerAction() {
  cout << "Choose an action for " << player->getName() << ":" << endl;
  cout << "1. Basic Attack" << endl;
  cout << "2. Defend" << endl;
  cout << "3. Use special skill" << endl;
  cout << "4. Use boost" << endl;
  cout << "5. Use ultimate skill" << endl;
  cout << "6. Use item" << endl;
  cout << "7. Save game" << endl;
  cout << "8. Quit game" << endl;

  bool validCommand = false;

  do {
    cout << "Enter the number of your choice: ";
    validCommand = true;

    int command;

    while (!(cin >> command)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input. Please enter a number between 1 and 6." << endl;
      cout << "Enter the number of your choice: ";
      continue;
    }

    cout << endl;

    switch (command) {
      case 1:
        player->basicAttack(enemy);
        break;

      case 2:
        player->defend();
        break;

      case 3:
        if (player->getSpecialSkillCounter() <= 0) {
          cout << "No Special skill charges left!" << endl;
          validCommand = false;
          break;
        }
        player->useSpecialSkill(enemy);
        break;;
        break;

      case 4:
        if (player->getBoostCounter() <= 0) {
          cout << "No boost charges left!" << endl;
          validCommand = false;
          break;
        }
        player->useBoost();
        break;

      case 5:
        if (player->getUltimateCounter() <= 0 || turnCounter < 2) {
          cout << "Ultimate skill not available!" << endl;
          validCommand = false;
          break;
        }
        player->useUltimateSkill(enemy);
        break;

      case 6: {
        if (player->getInventory().listItems() == "Empty\n") {
          cout << "No items available in inventory!" << endl;
          validCommand = false;
          break;
        }

        bool validItem = false;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        do {
          string chosenItem = "";
          cout << "Inventory items:\n"
               << player->getInventory().listItems() << endl;
          cout << "Enter the name of the item to use: ";
          getline(cin, chosenItem);

          try {
            player->getInventory().use(chosenItem);
            validItem = true;
          } catch (const exception& e) {
            cout << "Item \"" << chosenItem
                 << "\" not found or could not be used: " << e.what() << endl;
            cout << "Please enter a valid item.\n\n";
          } catch (...) {
            cout << "Unknown error using item \"" << chosenItem << "\".\n";
            cout << "Please try again.\n\n";
          }
        } while (!validItem);
        break;
      }
      case 7:
        cout << "Saving game...\n\n";
        saveGame();
        validCommand = false;
        break;
      case 8:
        cout << "Quitting game...\n";
        exit(0);
        break;
      default:
        cout << "Not sure how you got here, turn skipped." << endl;
        break;
    }
  } while (!validCommand);
}

// Checks for victory or defeat after each turn.
void BattleManager::checkWinCondition() {
  if (player->getHealthStat() <= 0) {
    cout << player->getName() << " has been defeated! Game Over." << endl;
    endBattle();
  } else if (enemy->getHealthStat() <= 0) {
    cout << enemy->getTypeName() << " has been defeated! You win!" << endl;
    endBattle();
  }
}

// Ends the current battle.
void BattleManager::endBattle() {
  isBattleActive = false;
}

#include <fstream>
#include <iostream>

void BattleManager::saveGame() {
    if (saveFileName.empty()) {
      cout << saveFileName << endl;
      cout << "No save file name specified. Cannot save game." << endl;
      return;
    }

    // Append .dat extension if not already included
    string fullFile = saveFileName;
    if (fullFile.find(".dat") == string::npos) {
        fullFile += ".dat";
    }

    // Open file for writing (overwrite existing)
    ofstream outFile(fullFile, ios::out | ios::trunc);
    if (!outFile) {
        cerr << "Error: Could not open " << fullFile << " for writing!" << endl;
        return;
    }

    // Write player data
    outFile << player->getName() << endl;
    outFile << player->getWeapon() << endl;
    outFile << player->getAttackStat() << endl;
    outFile << player->getDefenseStat() << endl;
    outFile << player->getHealthStat() << endl;
    outFile << player->getUniqueStat() << endl;

    // Write enemy data
    outFile << enemy->getTypeName() << endl;
    outFile << enemy->getAttackStat() << endl;
    outFile << enemy->getDefenseStat() << endl;
    outFile << enemy->getHealthStat() << endl;

    // --- Battle state ---
    outFile << turnCounter << endl;
    outFile << player->getUltimateCounter() << " "
            << player->getBoostCounter() << " "
            << player->getSpecialSkillCounter() << endl;
    // Close the file
    outFile.close();

    cout << "Game saved successfully to " << fullFile << "!" << endl;
}

int BattleManager::getTurnCounter(void)
{
  return turnCounter;
  
}
