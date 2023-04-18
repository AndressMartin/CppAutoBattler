#pragma once
#include "Grid.h"
#include "Character.h"
#include "Types.h"

class Character
{
public:
    Character(Types::CharacterClass characterClass);
    ~Character();

    float health;
    float baseDamage;
    float damageMultiplier;
    //public GridBox currentBox;
    int playerIndex;
    //public Character Target{ get; set; }

    Character* target;

    bool isDead;
    char icon;

    Types::GridBox currentBox;

    bool TakeDamage(float amount);

    int GetIndex(vector<Types::GridBox*> v, int index);

    void Die();

    void WalkTo(bool canWalk);

    void StartTurn(Grid* battlefield);

    bool CheckCloseTargets(Grid* battlefield);

    void Attack(Character* target);
};
