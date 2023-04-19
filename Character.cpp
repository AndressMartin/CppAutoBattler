#include "Grid.h"
#include "Character.h"
#include "Types.h"
#include "Character.h"
#include <vector>
#include <algorithm>
#include <iostream>

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
    this->damageMultiplier = attributes.damageMultiplier;
    this->icon = attributes.icon;
}

Character::~Character() = default;

bool Character::TakeDamage(float amount)
{
    if ((health -= baseDamage) <= 0)
    {
        Die();
        return true;
    }
    return false;
}

void Character::Die()
{
    // TODO >> kill
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
                std::cout << "Player " << 0 << " walked " << "LEFT" << '\n';
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
                std::cout << "Player " << 0 << " walked " << "RIGHT" << '\n';
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
                std::cout << "Player " << 0 << " walked " << "UP" << '\n';
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
                std::cout << "Player " << 0 << " walked " << "DOWN" << '\n';
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
    //TODO: Attack
}
