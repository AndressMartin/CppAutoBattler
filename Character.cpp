#include <vector>
#include <algorithm>
#include <iostream>
#include <random>
#include <cmath>
#include "Grid.h"
#include "Character.h"
#include "Types.h"
#include "Character.h"
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

constexpr int directions[][2] =
{
    {-1, 0}, // LEFT
    {1, 0},  // RIGHT
    {0, 1},  // DOWN
    {0, -1}  // UP
};

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
    isDead = true;
}

bool Character::CanWalk(Grid* battlefield, int x, int y)
{
    Types::GridBox* gridBox = battlefield->GetGridBox(currentBox->xIndex + x, currentBox->yIndex + y);
    return gridBox && !gridBox->occupied; //Already checks for nullPtr
}

void Character::WalkTo(Grid* battlefield, int x, int y)
{
    Types::GridBox* gridBox = battlefield->GetGridBox(currentBox->xIndex + x, currentBox->yIndex + y);
    if (gridBox)
    {
        const auto tempPtr = currentBox->occupied;
        currentBox->occupied = nullptr;
        gridBox->occupied = tempPtr;
        currentBox = gridBox;
    }
}

void Character::StartTurn(Grid* battlefield)
{
    if(target->isDead)
        return;
    if (CheckCloseTargets(battlefield))
    {
        Attack(target);
    }
    else // Calculates in which direction this character should move to be closer to a possible target
        {
        int bestDirectionIndex = -1;
        int bestDistance = INT_MAX; //Will be replaced by the distance found
        
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
            WalkTo(battlefield, directions[bestDirectionIndex][0], directions[bestDirectionIndex][1]);
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
}

bool Character::CheckCloseTargets(Grid* battlefield)
{

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
    int damage;

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
            damage = ceil(baseDamage * critModifier);
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
