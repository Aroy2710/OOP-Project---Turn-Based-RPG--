#ifndef __ACTION_H__
#define __ACTION_H__

// Action interface defines common combat behaviors for all entities
// in the game, such as attacking, defending, taking damage, and passive skills.
class Action {
 public:
  // Attacks given entity with a specified damage
  virtual void basicAttack(Action* entity, int damage) = 0;  
  // Defend against an attack; reduces damage from the next attack.
  virtual void defend() = 0;  
  // Applies a passive skill that is always active in battle.
  virtual void takeDamage(int damage) = 0; 
  // Default virtual destructor.
  virtual ~Action() = default;              
};

#endif // __ACTION_H__