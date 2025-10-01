class  Action
{
    public:
    virtual void basicAttack(Action* entity, int damage) = 0; //attacks entity with a given damage
    virtual void defend () = 0; // defend against an attack, takes less damage 
    virtual void passiveSkill() = 0; // buff that is always active in battle 
    virtual void takeDamage(int damage) = 0; //takes damage from an attack
    virtual ~Action() = default; //compiler-generated destructor
};
 