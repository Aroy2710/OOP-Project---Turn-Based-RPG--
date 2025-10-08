#include "Ranger.h"
// Ranger class if player does not provide name
Ranger::Ranger() : Player() {
  Player::setWeapon("Bow");
  dexterity = 1.5 * attackStat;
}
// Ranger class is player provides name
Ranger::Ranger(string name) : Player(name) {
  Player::setWeapon("Bow");
  dexterity = 1.5 * attackStat;
}

// Paramaterised constructor for testing purposes
Ranger::Ranger(string name, string weapon, float attackStat, float defenseStat,
               float healthStat)
    : Player(name, weapon, attackStat, defenseStat, healthStat) {
  dexterity = 1.5 * attackStat;
}
// getter
float Ranger::getDexterity() { return dexterity; }
// players can boost their dex and therefore their damage increases
void Ranger::boostDex() {  // will need battle manager class to account for turn
                           // cooldown
  if (useCounter > 0) {
    dexterity += 30;
    useCounter -= 1;

  } else {
    if (gameText) {
      cout << "You have used all your charges for your boost" << endl;
    }
  }
}

void Ranger::useUltimateSkill(Action* entity) {
  if (gameText) {
    cout << "Drawing every ounce of focus... ultimate shot fired!" << endl;
  }

  int damage = (attackStat *1.5) + (dexterity*0.8);
  if (ultimateCounter > 0) {
    entity->takeDamage(damage);
    ultimateCounter -= 1; 
  } else {
    if (gameText) {
      cout << "You have used up your charge for ultimate skill.." << endl;
    }
  }
}

Ranger::~Ranger() {}
