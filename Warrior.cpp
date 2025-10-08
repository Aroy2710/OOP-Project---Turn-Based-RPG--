#include "Warrior.h"
// Warrior class if player does not provide name
//strength will always half of attack
Warrior::Warrior() : Player() {
  Player::setWeapon("Club");
  
  strength = (50/100) * attackStat;
}
// Warrior class is player provides name
Warrior::Warrior(string name): Player(name) {
  Player::setWeapon("Club");
  strength = (50/100) * attackStat;
}

// Paramaterised constructor for testing purposes
Warrior::Warrior(string name, string weapon, float attackStat, float defenseStat,
               float healthStat)
    : Player(name, weapon, attackStat, defenseStat, healthStat) {
  strength = 1.5 * attackStat;
}
// getter
float Warrior::getStrength() { return strength; }
// players can boost their dex and therefore their damage increases
void Warrior::boostStrength() {  // will need battle manager class to account for turn
                           // cooldown
  if (useCounter > 0) {
    strength += 30;
    useCounter -= 1;

  } else {
    if (gameText) {
      cout << "You have used all your charges for your boost" << endl;
    }
  }
}

void Warrior::useUltimateSkill(Action* entity) {
  if (gameText) {
    cout << "Summoning all their strength, the final blow is delivered!" << endl;
  }

  float damage = (attackStat *1.5) + (strength*0.8);
  if (ultimateCounter > 0) {
    entity->takeDamage(damage);
    ultimateCounter -= 1; 
  } else {
    if (gameText) {
      cout << "You have used up your charge for ultimate skill.." << endl;
    }
  }
}

Warrior::~Warrior() {}
