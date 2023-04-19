#pragma once
#include <memory>
#include "Grid.h"
#include "Character.h"
#include "Classes.h"
#include "Types.h"
#include "StatusEffects/BaseStatusEffect.h"

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
    
    bool CanWalk(Grid* battlefield, int x, int y);
    
    void WalkTo(Grid* battlefield, int x, int y);

    void StartTurn(Grid* battlefield);

    bool CheckCloseTargets(Grid* battlefield);
    
    bool CheckDirections(Grid* battlefield, int x, int y);

    void Attack(Character* target);
    
    AttackOutcome CalculateAttackOutcome();
    
    void ApplyStatusEffect(std::unique_ptr<StatusEffects::BaseStatusEffect> effect);
    
    void ApplyStatusEffects();
};