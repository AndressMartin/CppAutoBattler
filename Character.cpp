#include <vector>
#include <algorithm>
#include <iostream>
#include <random>
#include <cmath>
#include "Grid.h"
#include "Character.h"
#include "Types.h"
#include "Utils.h"
#include "Classes.h"
#include "Abilities/SpecialAbilityFactory.h"
#include "StatusEffects/StatusEffectFactory.h"

using namespace std;
using namespace StatusEffects;
using namespace Types;

Character::Character(Classes::CharacterClass characterClass)
: characterClass(characterClass)
{
    static const Classes::ClassDatabase class_database;
    const Classes::ClassAttributes& attributes = class_database.GetAttributes(characterClass);

    this->characterClass = characterClass;
    this->health = attributes.health;
    this->baseDamage = attributes.baseDamage;
    this->critModifier = attributes.critMultiplier;
    this->critChance = attributes.critChance;
    this->statusEffects = attributes.statusEffects;
    this->specialAbilities = attributes.specialAbilities;
    this->statusInflictChance = attributes.statusInflictChance;
    this->abilityChance = attributes.abilityChance;
    this->range = attributes.range;
    this->icon = attributes.icon;
}

Character::~Character() = default;

constexpr int directions[][2] =
{
    {-1, 0}, // LEFT
    {1, 0},  // RIGHT
    {0, 1},  // DOWN
    {0, -1}  // UP
};

void Character::TakeDamage(float amount)
{
    if(isDead)
        return;
    health -= amount;
    cout << charName << "'s " <<Classes::StringifyCharacterClass[characterClass] << " took " << amount << " damage.\n";
    HandleStatusEffectsProc(ProcEvent::OnTookDamage);
    if (health <= 0 && !isDead)
    {
        Die();
    }
}

void Character::Heal(float amount)
{
    if(isDead)
        return;
    health += amount;
    cout << charName << "'s " <<Classes::StringifyCharacterClass[characterClass] << " heals " << amount << " health.\n";
}

void Character::Die()
{
    cout << charName << "'s " <<Classes::StringifyCharacterClass[characterClass] << " is dead!\n";
    isDead = true;
}

bool Character::CanWalk(Grid* battlefield, int x, int y)
{
    GridBox* gridBox = battlefield->GetGridBox(currentBox->xIndex + x, currentBox->yIndex + y);
    return gridBox && !gridBox->occupied; //Already checks for nullPtr
}

void Character::WalkTo(Grid* battlefield, int x, int y, Character* character)
{
    GridBox* gridBox = battlefield->GetGridBox(character->currentBox->xIndex + x, character->currentBox->yIndex + y);
    if (gridBox)
    {
        const auto tempPtr = character->currentBox->occupied;
        character->currentBox->occupied = nullptr;
        gridBox->occupied = tempPtr;
        character->currentBox = gridBox;
    }
}

void Character::HandleTurn(Grid* battlefield)
{
    if(target->isDead)
        return;
    
    HandleStatusEffectsProc(ProcEvent::OnStartOfTurn);
    
    if(target->isDead) //Repeated due to status timing
        return;

    if(actionBlocked) //eg. Frozen Status
    {
        actionBlocked = false;
        return;
    }
    
    if (CheckCloseTargets(battlefield))
    {
        HandleStatusEffectsProc(ProcEvent::OnAboutToAttack);

        if(attackBlocked) //eg. Fearful Status
        {
            attackBlocked = false;
            return;
        }

        ChooseAttackOrAbility(battlefield);
    }
    else //Calculates in which direction this character should move to be closer to a possible target
        {
        int bestDirectionIndex = -1;
        int bestDistance = INT_MAX; //Replaced by the distance found
        
        for (int i = 0; i < 4; ++i) {
            const int newX = currentBox->xIndex + directions[i][0];
            const int newY = currentBox->yIndex + directions[i][1];
            if (CanWalk(battlefield, directions[i][0], directions[i][1])) {
                const int distance = abs(newX - target->currentBox->xIndex) + abs(newY - target->currentBox->yIndex);
                if (distance < bestDistance) {
                    bestDistance = distance;
                    bestDirectionIndex = i;
                }
            }
        }

        if (bestDirectionIndex >= 0) {
            WalkTo(battlefield, directions[bestDirectionIndex][0], directions[bestDirectionIndex][1], this);
            cout << "Player " << Classes::StringifyCharacterClass[characterClass] << " walked ";
            if (bestDirectionIndex == 0) cout << "LEFT";
            else if (bestDirectionIndex == 1) cout << "RIGHT";
            else if (bestDirectionIndex == 2) cout << "DOWN";
            else if (bestDirectionIndex == 3) cout << "UP";
            cout << '\n';
        }
        else {cout << "Something went wrong with the movement\n";}

        battlefield->DrawBattlefield();
    }
    HandleStatusEffectsProc(ProcEvent::OnEndOfTurn);
}

void Character::ChooseAttackOrAbility(Grid* battlefield)
{
    int chance = Utils::GetRandomInt(0, 100);
    if (chance < abilityChance)
    {
        UseSpecialAbility(battlefield);
    }
    else
    {
        Attack();
    }
}

bool Character::CheckCloseTargets(Grid* battlefield)
{
    for (const auto& direction : directions)
    {
        for (int i = 1; i <= range; ++i)
        {
            if (CheckDirections(battlefield, currentBox->xIndex + direction[0] * i, currentBox->yIndex + direction[1] * i))
                return true;
        }
    }

    return false;
}

bool Character::CheckDirections(Grid* battlefield, int x, int y)
{
    if (const auto gridBox = battlefield->GetGridBox(x, y))
    {
        if (gridBox->occupied)
        {
            return true;
        }
        return false;
    }
    return false;
}

void Character::Attack()
{
    AttackOutcome outcome = CalculateAttackOutcome();
    int damage = baseDamage + damageModifiers;
    bool successfulHit = false;
    int randomChance = Utils::GetRandomInt(0, 100);
    bool canInflict = randomChance <= statusInflictChance && target->statusEffects_inflicted.empty();

    switch (outcome)
    {
        case AttackOutcome::Miss:
            cout << Classes::StringifyCharacterClass[characterClass] << " missed!\n";
            return;
        case AttackOutcome::Hit:
            cout << Classes::StringifyCharacterClass[characterClass] << " hits for " << damage << ". ";
            successfulHit = true;
            break;
        case AttackOutcome::Crit:
            damage = ceil(damage * critModifier);
            cout << Classes::StringifyCharacterClass[characterClass] << " CRITS for " << damage << "! ";
            successfulHit = true;
            break;
    }
    target->TakeDamage(damage);

    if (successfulHit)
    {
        if(canInflict)
        {
            // Loop through the character's possible status effects
            for (const StatusEffect& effectType : statusEffects)
            {
                // Create the correct status effect instance
                auto statusEffect = CreateStatusEffect(effectType, *this);

                // Inflict the status effect on the target
                if (statusEffect)
                {
                    statusEffect->Inflict(*target);
                    cout << charName << " inflicted " << StringifyStatusEffect[(int)effectType]
                    << " on " << target->charName <<".\n";
                }
            }
        }
        HandleStatusEffectsProc(ProcEvent::OnSuccessfulAttack);
    }
}

AttackOutcome Character::CalculateAttackOutcome()
{
    const int randomValue = Utils::GetRandomInt(-10, 100);
    
    if (randomValue <= 0)
    {
        return AttackOutcome::Miss;
    }
    if (randomValue < 100 - critChance)
    {
        return AttackOutcome::Hit;
    }
    return AttackOutcome::Crit;
}

void Character::GetInflictedWithStatus(std::unique_ptr<BaseStatusEffect> status)
{
    statusEffects_inflicted.push_back(std::move(status));
}

void Character::RemoveStatusEffect(BaseStatusEffect* effectToRemove)
{
    cout << charName << " is no longer afflicted.\n";
    statusEffects_inflicted.erase(
    std::remove_if(statusEffects_inflicted.begin(), statusEffects_inflicted.end(),
        [&](const std::unique_ptr<BaseStatusEffect>& effect)
        {
            return effect.get() == effectToRemove;
        }),
    statusEffects_inflicted.end());
}

void Character::HandleStatusEffectsProc(ProcEvent procEvent)
{
    for (auto& effect : statusEffects_inflicted)
    {
        if (effect->ShouldProcOnEvent(procEvent))
        {
            effect->Proc();
        }
    }
}

void Character::UseSpecialAbility(Grid* battlefield)
{
    int randomIndex = Utils::GetRandomInt_MaxExclusive(0, specialAbilities.size());
    auto chosenAbility = specialAbilities[randomIndex];
    auto abilityInstance = SpecialAbilities::CreateSpecialAbility(chosenAbility);
    if (abilityInstance && abilityInstance->CanUse(*this, *target))
    {
        abilityInstance->Execute(*this, *target, battlefield);
    }
    else
    {
        ChooseAttackOrAbility(battlefield);
    }
}