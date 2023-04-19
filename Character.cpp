#include "Grid.h"
#include "Character.h"
#include "Types.h"
#include "Character.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>
#include "Utils.h"

#include "Classes.h"

using namespace std;

Character::Character(Classes::CharacterClass characterClass)
: characterClass(characterClass)
{
    static const Classes::ClassDatabase classDatabase;
    const Classes::ClassAttributes& attributes = classDatabase.GetAttributes(characterClass);

    this->characterClass = characterClass;
    this->health = attributes.health;
    this->baseDamage = attributes.baseDamage;
    this->critModifier = attributes.critMultiplier;
    this->critChance = attributes.critChance;
    this->icon = attributes.icon;
}

Character::~Character() = default;

void Character::TakeDamage(float amount)
{
    cout << Classes::StringifyCharacterClass[characterClass] << " took " << amount << " damage!\n";
    if ((health -= amount) <= 0)
    {
        Die();
    }
}

void Character::Die()
{
    std::cout << Classes::StringifyCharacterClass[characterClass] << " is dead!\n";
    //TODO >> kill
    //TODO >> end the game?
}

void Character::WalkTo(bool canWalk)
{
    
}


void Character::StartTurn(Grid* battlefield)
{
    if (CheckCloseTargets(battlefield))
    {
        Attack(target);
    }
    else // Calculates in which direction this character should move to be closer to a possible target
    {
        if (currentBox->xIndex > target->currentBox->xIndex)
        {
            if (Types::GridBox* gridBox = battlefield->GetGridBox(currentBox->xIndex -1, currentBox->yIndex))
            {
                auto tempPtr = currentBox->occupied;
                currentBox->occupied = nullptr;
                gridBox->occupied = tempPtr;
                currentBox = gridBox;
                std::cout << "Player " << Classes::StringifyCharacterClass[characterClass] << " walked " << "LEFT" << '\n';
            }
        }
        else if (currentBox->xIndex < target->currentBox->xIndex)
        {
            if (Types::GridBox* gridBox = battlefield->GetGridBox(currentBox->xIndex +1, currentBox->yIndex))
            {
                auto tempPtr = currentBox->occupied;
                currentBox->occupied = nullptr;
                gridBox->occupied = tempPtr;
                currentBox = gridBox;
                std::cout << "Player " << Classes::StringifyCharacterClass[characterClass] << " walked " << "RIGHT" << '\n';
            }
        }
        else if (currentBox->yIndex > target->currentBox->yIndex)
        {
            if (Types::GridBox* gridBox = battlefield->GetGridBox(currentBox->xIndex, currentBox->yIndex -1))
            {
                auto tempPtr = currentBox->occupied;
                currentBox->occupied = nullptr;
                gridBox->occupied = tempPtr;
                currentBox = gridBox;
                std::cout << "Player " << Classes::StringifyCharacterClass[characterClass] << " walked " << "UP" << '\n';
            }
        }
        else if (currentBox->yIndex < target->currentBox->yIndex)
        {
            if (Types::GridBox* gridBox = battlefield->GetGridBox(currentBox->xIndex, currentBox->yIndex +1))
            {
                auto tempPtr = currentBox->occupied;
                currentBox->occupied = nullptr;
                gridBox->occupied = tempPtr;
                currentBox = gridBox;
                std::cout << "Player " << Classes::StringifyCharacterClass[characterClass] << " walked " << "DOWN" << '\n';
            }
        }
        battlefield->DrawBattlefield();
    }
}

bool Character::CheckCloseTargets(Grid* battlefield)
{
    constexpr int directions[][2] = {
        {-1, 0}, // LEFT
        {1, 0},  // RIGHT
        {0, 1},  // DOWN
        {0, -1}  // UP
    };

    // std::cout << '\n' << currentBox->xIndex << ", " << currentBox->yIndex << '\n';
    for (const auto& direction : directions)
    {
        // std::cout << "Directions: " << direction[0] << ", " << direction[1] << '\t';
        if (CheckDirections(battlefield, currentBox->xIndex + direction[0], currentBox->yIndex + direction[1]))
        {
            return true;
        }
    }

    return false;
}

bool Character::CheckDirections(Grid* battlefield, int x, int y)
{
    //Already checks for nullPtr.
    // std::cout << x << ", " << y << '\t';
    if (const auto gridBox = battlefield->GetGridBox(x, y))
    {
        if (gridBox->occupied)
        {
            // std::cout << "Occupied\n";
            return true;
        }
        
        // std::cout << "Free\n";
        return false;
    }
    else
    {
        // std::cout << "INVALID\n";
        return false;
    }
}

void Character::Attack(Character* target)
{
    AttackOutcome outcome = CalculateAttackOutcome();
    float damage;

    switch (outcome)
    {
        case AttackOutcome::Miss:
            cout << Classes::StringifyCharacterClass[characterClass] << " missed!\n";
            return;
        case AttackOutcome::Hit:
            damage = baseDamage;
            cout << Classes::StringifyCharacterClass[characterClass] << " hits for " << damage << "!\n";
            break;
        case AttackOutcome::Crit:
            damage = baseDamage * critModifier;
            cout << Classes::StringifyCharacterClass[characterClass] << " CRITS for " << damage << "!\n";
            break;
    }

    target->TakeDamage(damage);
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
