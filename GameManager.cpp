#include "GameManager.h"
/**
 *Constructs a new GameManager and immediately shows the main menu.
 */
GameManager::GameManager() {
  showMainMenu();
  saveFileExists = false;
}

/**
 * Destructor cleans up dynamically allocated game resources.
 */
GameManager::~GameManager() {
  delete player;
  delete enemy;
  delete currentBattle;
}

/**
 * Starts a new game session by creating a player, selecting an enemy,
 * and starting a battle.
 */
void GameManager::startNewGame() {
  cout << "Please enter your character's name: ";
  string playerName;
  cin.ignore();
  getline(cin, playerName);

  bool validChoice = true;
  int archetypeChoice;

  // Select player archetype (Warrior, Mage, Ranger)
  do {
    validChoice = true;

    cout << "Choose your archetype:\n"
         << "1. Warrior\n"
         << "2. Mage\n"
         << "3. Ranger\n";
    cout << "Enter the number of your choice: ";
    cin >> archetypeChoice;

    if (archetypeChoice < 1 || archetypeChoice > 3) {
      cout << "Invalid choice. Please choose a valid archetype.\n";
      validChoice = false;
    }
  } while (!validChoice);

  int classType;

  // Choose subclass based on archetype
  do {
    validChoice = true;

    if (archetypeChoice == 1) {
      // --- Warrior intro and selection ---
      cout << "\n=== Warrior ===\n"
           << "Warriors are frontline fighters who rely on raw strength.\n"
           << "Use boosts to spike your Strength, and unleash a high-impact "
              "ultimate that hits even harder when your health is low.\n\n";

      cout << "Please choose your warrior type:\n"
           << "1. Swordsman- a disciplined fighter who trades health for explosive power.\n"
           << "2. Barbarian - a fierce brawler who gains strength at the cost of defense, favoring raw aggression\n";
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
      // --- Mage intro and selection ---
      cout << "\n=== Mage ===\n"
           << "Mages are powerful spellcasters who trade endurance for immense "
              "magical damage.\n"
           << "They wield elemental and arcane power, excelling at offense but "
              "vulnerable in defense.\n"
           << "Manage your mana wisely—boosting it increases your magical "
              "potential.\n\n";

      cout << "Please choose your mage type:\n"
           << "1. Wizard - manipulates raw mana for a powerful fireball spell, "
              "but sacrifices health in battle\n"
           << "2. Warlock - unleashes an eldritch blast based on their max "
              "health and restores vitality\n";
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
      // --- Ranger intro and selection ---
      cout << "\n=== Ranger ===\n"
           << "Rangers are agile marksmen who fight from range using precision "
              "and speed.\n"
           << "Their attacks scale with Dexterity, making accuracy their "
              "strongest weapon.\n"
           << "Use boosts to sharpen focus and power up their strikes.\n\n";

      cout << "Please choose your ranger type:\n"
           << "1. Archer - a precise marksman whose attacks grow stronger with every shot.\n"
           << "2. Gunner - a tactical fighter who delivers precise bursts and hardens defense after each shot.\n";
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

  cout << "Character created successfully! Welcome, "
       << player->getName() << "!\n";

  // --- Enemy selection ---
  int enemyChoice;
  do {
    validChoice = true;

    cout << "Please choose an enemy to battle:\n"
         << "1. Goblin - a reckless brawler that grows more dangerous as its health drops, using Bleed Damage to strike harder with each attack.\n"
         << "2. Orc - a brutal warrior who relies on raw strength and defense, going berserk at low health to attack relentlessly with devastating force.\n"
         << "3. Human - disciplined fighter who balances offense and defense, doubling their power in a rage when their health runs low.\n";
    cout << "Enter the number of your choice: ";
    cin >> enemyChoice;

    if (enemyChoice == 1) {
      enemy = new Goblin();
    } else if (enemyChoice == 2) {
      enemy = new Orc();
    } else if (enemyChoice == 3) {
      enemy = new Human();
    } else {
      cout << "Invalid choice. Please choose a valid enemy.\n";
      validChoice = false;
    }
  } while (!validChoice);

  // --- Save file name setup ---
  cout << "Please enter a save file name (default: savegame.dat): ";
  cin >> saveFileName;

  system("clear");

  // --- Start battle ---
  currentBattle = new BattleManager(player, enemy);
  currentBattle->startBattle();
}

/**
 * Displays the main menu and handles menu navigation.
 */
void GameManager::showMainMenu() {
  cout << "Welcome to the Turn-Based RPG!" << endl
       << "1. Start New Game" << endl
       << "2. Load Game" << endl
       << "3. Quit" << endl;

  int choice;
  bool validChoice = true;

  do {
    validChoice = true;
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

/**
 * @Placeholder for loading a saved game file.
 */
void GameManager::loadGame() {
  cout << "Load game functionality not yet implemented." << endl;
}

/**
 * @Placeholder for saving the current game state.
 */
void GameManager::saveGame() {
  cout << "Save game functionality not yet implemented." << endl;
}

/**
 * Quits the game after saving progress.
 */
void GameManager::quitGame() {
  saveGame();
  cout << "Thank you for playing! Goodbye." << endl;
  exit(0);
}
