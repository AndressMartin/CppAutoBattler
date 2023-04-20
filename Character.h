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
    Crit,
};

class Character
{
public:
    Character(Classes::CharacterClass characterClass);
    ~Character();

    std::string charName;
    char icon;

    int health;
    int baseDamage;
    int damageModifiers;
    float critModifier;
    int critChance;
    std::vector<Types::StatusEffect> statusEffects;
    std::vector<Types::SpecialAbility> specialAbilities;
    int statusInflictChance;
    int abilityChance;

    bool isDead;
    bool attackBlocked;
    bool actionBlocked;
    
    Character* target;
    Types::GridBox* currentBox;
    Classes::CharacterClass characterClass;

    void TakeDamage(float amount);
    void Heal(float amount);
    int GetIndex(std::vector<Types::GridBox*> v, int index);
    void Die();
    bool CanWalk(Grid* battlefield, int x, int y);
    void WalkTo(Grid* battlefield, int x, int y, Character* character);
    void HandleTurn(Grid* battlefield);
    void ChooseAttackOrAbility(Grid* battlefield);
    bool CheckCloseTargets(Grid* battlefield);
    bool CheckDirections(Grid* battlefield, int x, int y);
    void Attack();
    AttackOutcome CalculateAttackOutcome();
    void ApplyRandomStatusEffect();
    void GetInflictedWithStatus(std::unique_ptr<StatusEffects::BaseStatusEffect> status);
    void RemoveStatusEffect(StatusEffects::BaseStatusEffect* effectToRemove);
    void HandleStatusEffectsProc(Types::ProcEvent procEvent);
    void UseSpecialAbility(Grid* battlefield);
    std::vector<std::unique_ptr<StatusEffects::BaseStatusEffect>> statusEffects_canInflict;
    std::vector<std::unique_ptr<StatusEffects::BaseStatusEffect>> statusEffects_inflicted;
};