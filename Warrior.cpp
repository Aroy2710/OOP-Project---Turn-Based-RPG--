#include "Warrior.h"

// Default constructor.
// Initializes a Warrior with default Player attributes.
// The Warrior's weapon defaults to "Club".
// Strength is set to 50% of the attack stat.
Warrior::Warrior() : Player() {
  Player::setWeapon("Club");
  strength = 0.5f * attackStat;
}

// Constructor for Warrior with a custom name.
// The Warrior's weapon defaults to "Club".
// Strength is set to 50% of the attack stat.
Warrior::Warrior(std::string name) : Player(name) {
  Player::setWeapon("Club");
  strength = 0.5f * attackStat;
}

// Parameterized constructor.
// Useful for testing with explicit stat values.
// Strength is initialized to 0.5× attack stat.
Warrior::Warrior(std::string name, std::string weapon, float attack_stat,
                 float defense_stat, float health_stat)
    : Player(name, weapon, attack_stat, defense_stat, health_stat) {
  strength = 0.5f * attackStat;
}

float Warrior::getUniqueStat() const 
{
  if (gameText)
  {
    cout<< "Player STR:          " ;
  }
  
  
  return strength;
  
}

void Warrior::setUniqueStat(float value) 
{
  strength = value;
}

// Each use consumes one available boost charge.
// Requires an external battle manager to enforce cooldowns.
void Warrior::useBoost() {
  if (boostCounter > 0) {
    if (gameText)
    {
      cout<<name<<"'s strength has been boosted by 30 points! "<<endl;

    }
    

    strength += 30.0f;
    boostCounter -= 1;
  } else if (gameText) {
    std::cout << "You have used all your charges for your boost."
              << std::endl;
  }
}

// Uses the Warrior's ultimate skill on a target entity.
// Damage output depends on current health:
// - Below 50% health: higher damage multiplier.
// - Above 50% health: lower damage multiplier.
void Warrior::useUltimateSkill(Entity* entity) {
  if (!entity) {
    if (gameText) std::cout << name << " tried to attack, but there's no target!\n";
    return;
  }
  float damage = 0.0f;

  // Damage scaling based on current health percentage.
  if (healthStat < 0.5f * maxHealth) {
    damage = 4.0f * strength + 2.0f * attackStat;
  } else {
    damage = 2.0f * strength + attackStat;
  }

  if (ultimateCounter > 0) {
    if (gameText) {
      std::cout << "The warrior musters up all their strength!" << std::endl;
    }

    entity->takeDamage(damage);
    ultimateCounter -= 1;

  } else if (gameText) {
    std::cout << "You have used up your charge for your ultimate skill."
              << std::endl;
  }
}

// Destructor.
Warrior::~Warrior() = default;
