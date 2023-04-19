#pragma once
#include "Grid.h"
#include "Character.h"
#include "Classes.h"
#include "Types.h"

enum class AttackOutcome
{
    Miss,
    Hit,
    Crit
};

class Character
{
public:
    Character(Classes::CharacterClass characterClass);
    ~Character();

    int health;
    int baseDamage;
    float critModifier;
    int critChance;
    int playerIndex;

    bool isDead;
    char icon;
    
    Character* target;
    Types::GridBox* currentBox;
    Classes::CharacterClass characterClass;

    void TakeDamage(float amount);

    int GetIndex(std::vector<Types::GridBox*> v, int index);

    void Die();

    void WalkTo(bool canWalk);

    void StartTurn(Grid* battlefield);

    bool CheckCloseTargets(Grid* battlefield);
    bool CheckDirections(Grid* battlefield, int x, int y);

    void Attack(Character* target);
    AttackOutcome CalculateAttackOutcome();
};