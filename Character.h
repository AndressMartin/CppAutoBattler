#pragma once
#include <memory>
#include "Grid.h"
#include "Character.h"
#include "Classes.h"
#include "Types.h"
#include "StatusEffects/BaseStatusEffect.h"

using namespace StatusEffects;

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

    std::string charName;
    int health;
    int baseDamage;
    float critModifier;
    int critChance;
    std::vector<Types::StatusEffect> statusEffects;
    int statusInflictChance;

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
    void ApplyRandomStatusEffect();
    void GetInflictedWithStatus(std::unique_ptr<BaseStatusEffect> status);
    void RemoveStatusEffect(BaseStatusEffect* effectToRemove);
    std::vector<std::unique_ptr<BaseStatusEffect>> statusEffects_canInflict;
    std::vector<std::unique_ptr<BaseStatusEffect>> statusEffects_inflicted;
};