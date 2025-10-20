#include "Mage.h"

// Default constructor.
// Initializes a Mage with default Player attributes.
// The Mage's weapon defaults to "Staff".
// Mana is set to 2.0× the attack stat.
// Mage has 25% less health than other classes in exchange for more damage
Mage::Mage() : Player() {
  Player::setWeapon("Staff");
  mana = 2.0f * attackStat;
  healthStat = 0.75*healthStat;
  
}

// Constructor for Mage with a custom name.
// The Mage's weapon defaults to "Staff".
// Mana is set to 1.5× the attack stat.
// Mage has 25% less health than other classes in exchange for more damage
Mage::Mage(std::string name) : Player(name) {
  Player::setWeapon("Staff");
  mana = 2.0f * attackStat;
  healthStat = 0.75*healthStat;
}

// Parameterized constructor.
// Useful for testing with explicit stat values.
// Mana is initialized to 2.0 attack stat.
Mage::Mage(std::string name, std::string weapon, float attack_stat,
               float defense_stat, float health_stat)
    : Player(name, weapon, attack_stat, defense_stat, health_stat) {
  mana = 2.0f * attackStat;
}

float Mage::getUniqueStat() const 
{
  return mana;
  
}

// Increases the Mage's mana
// Each use consumes one available boost charge.
// Requires an external battle manager to enforce cooldowns.
void Mage::useBoost() {
  if (boostCounter > 0) {
    if (gameText)
    {
      cout<<name<<"'s mana has been boosted by 30 points! "<<endl;
      
    }
    
    mana += 30.0f;
    boostCounter -= 1;
  } else if (gameText) {
    std::cout << "You have used all your charges for your boost."
              << std::endl;
  }
}

// Uses the Mage's ultimate skill on a target entity.
// The attack combines precision (dexterity) and power (attack stat).
void Mage::useUltimateSkill(Action* entity) {
  if (!entity) {
    if (gameText) std::cout << name << " tried to attack, but there's no target!\n";
    return;
  }
  if (ultimateCounter > 0) {
    float damage = (attackStat * 2.0f) + (mana * 2.0f);

    entity->takeDamage(damage);

    if (gameText) {
      std::cout << "The Mage calls upon the light from the heavens!"
                << std::endl;
    }

    ultimateCounter -= 1;
  } else if (gameText) {
    std::cout << "You have used up your charge for your ultimate skill."
              << std::endl;
  } 
}

// Destructor.
Mage::~Mage() = default;
