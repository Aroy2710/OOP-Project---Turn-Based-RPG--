#include "Ranger.h"

// Default constructor.
// Initializes a Ranger with default Player attributes.
// The Ranger's weapon defaults to "Bow".
// Dexterity is set to 1.5× the attack stat.
Ranger::Ranger() : Player() {
  Player::setWeapon("Bow");
  dexterity = 1.5f * attackStat;
}

// Constructor for Ranger with a custom name.
// The Ranger's weapon defaults to "Bow".
// Dexterity is set to 1.5× the attack stat.
Ranger::Ranger(std::string name) : Player(name) {
  Player::setWeapon("Bow");
  dexterity = 1.5f * attackStat;
}

// Parameterized constructor.
// Useful for testing with explicit stat values.
// Dexterity is initialized to 1.5× attack stat.
Ranger::Ranger(std::string name, std::string weapon, float attack_stat,
               float defense_stat, float health_stat)
    : Player(name, weapon, attack_stat, defense_stat, health_stat) {
  dexterity = 1.5f * attackStat;
}

// Returns the Ranger's current dexterity value.
float Ranger::getUniqueStat() const 
{
  if (gameText)
  {
    cout<< "Player DEX:           " ;
    
  }
  
  
  return dexterity;
  
}

// Sets the Ranger's dexterity to a specific value.
void Ranger::setUniqueStat(float value) {
  dexterity = value;
}


// Each use consumes one available boost charge.
// Requires an external battle manager to enforce cooldowns.
void Ranger::useBoost() {
  if (boostCounter > 0) {
    if(gameText){
      cout<<name<<"'s dexterity has been boosted by 30 points! "<<endl;
    }
    dexterity += 30.0f;
    boostCounter -= 1;
  } else if (gameText) {
    std::cout << "You have used all your charges for your boost."
              << std::endl;
  }
}

// Uses the Ranger's ultimate skill on a target entity.
// The attack combines precision (dexterity) and power (attack stat).
void Ranger::useUltimateSkill(Entity* entity) {
  if (!entity) {
    if (gameText) std::cout << name << " tried to attack, but there's no target!\n";
    return;
  }
  if (ultimateCounter > 0) {
    float damage = 2.5*((attackStat * 1.5f) + (dexterity * 0.8f));

    

    if (gameText) {
      std::cout << "Drawing every ounce of focus... ultimate shot fired!"
                << std::endl;
    }
    entity->takeDamage(damage);

    ultimateCounter -= 1;
  } else if (gameText) {
    std::cout << "You have used up your charge for your ultimate skill."
              << std::endl;
  }
}

// Destructor.
Ranger::~Ranger() = default;
