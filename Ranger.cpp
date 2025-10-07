#include "Ranger.h"
Ranger::Ranger() : Player() { dexterity = 1.5 * attackStat; }

Ranger::Ranger(string name) : Player(name) { dexterity = 1.5 * attackStat; }

Ranger::Ranger(string name, string weapon, int attackStat, int defenseStat,
               int healthStat)
    : Player(name, weapon, attackStat, defenseStat, healthStat) {
  dexterity = 1.5 * attackStat;
}

int Ranger::getDexterity() { return dexterity; }

void Ranger::boostDex() {  // will need battle manager class to account for turn
                           // cooldown class
  if (useCounter > 0) {
    dexterity += 30;
    useCounter -= 1;

  } else {
    if (gameText) {
      cout << "You have used all your charges for special skills" << endl;
    }
  }
}

void Ranger::useUltimateSkill(Action* entity) {
  if (gameText) {
    cout << "Drawing every ounce of focus... ultimate shot fired!" << endl;
  }

  int damage = (attackStat * 1.5) + (dexterity * 0.8);
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
