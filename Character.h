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
    int playerIndex;

    bool isDead;
    char icon;
    
    Character* target;
    Types::GridBox currentBox;
    Types::CharacterClass characterClass;

    bool TakeDamage(float amount);

    int GetIndex(std::vector<Types::GridBox*> v, int index);

    void Die();

    void WalkTo(bool canWalk);

    void StartTurn(Grid* battlefield);

    bool CheckCloseTargets(Grid* battlefield);

    void Attack(Character* target);

    // friend std::ostream& operator<<(std::ostream& os, const Character& characterClass);
};
