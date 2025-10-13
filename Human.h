#ifndef __HUMAN_H__
#define __HUMAN_H__

class Human : public Player{
    public:
    Human();
    explicit Human(float attackStat, float defenseStat, float healthStat);

    void bruteForce(Action* entity);
    void useUltimateSkill(Action* entity) override;
    void performTurn(Action* entity);

    ~Human();

};

#endif