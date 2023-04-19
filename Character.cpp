#include "Grid.h"
#include "Character.h"
#include "Types.h"
#include "Character.h"
#include <vector>
#include <algorithm>

using namespace std;

Character::Character(Types::CharacterClass characterClass) //TODO: Check this struct initialization, do I really need to initialize currentBox?
: currentBox(0, 0, false, 0), characterClass(characterClass)
{
}

Character::~Character()
= default;

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
    // {
    //     if (CheckCloseTargets(battlefield))
    //     {
    //         Attack(Character::target);
    //
    //
    //         return;
    //     }
    //     else
    //     {
    //         // if there is no target close enough, calculates in wich direction this character should move to be closer to a possible target
    //         
    //         if (currentBox.xIndex > target->currentBox.xIndex)
    //         {
    //             auto it = std::find_if(battlefield->grids.begin(), battlefield->grids.end(), [index = currentBox.index - 1](const Types::GridBox& gridBox) {
    //                 return gridBox.index == index;
    //             });
    //
    //             if (it != battlefield->grids.end())
    //             {
    //                 currentBox.occupied = false;
    //                 battlefield->grids[currentBox.index] = currentBox;
    //
    //                 currentBox = (battlefield->grids[currentBox.index - 1]);
    //                 currentBox.occupied = true;
    //                 battlefield->grids[currentBox.index] = currentBox;
    //                 //Console.WriteLine($"Player {PlayerIndex} walked left\n");
    //                 battlefield->DrawBattlefield(5, 5);
    //
    //                 return;
    //             }
    //         }
    //         else if (currentBox.xIndex < target->currentBox.xIndex)
    //         {
    //             currentBox.occupied = false;
    //             battlefield->grids[currentBox.index] = currentBox;
    //             currentBox = (battlefield->grids[currentBox.index + 1]);
    //             return;
    //             battlefield->grids[currentBox.index] = currentBox;
    //             //Console.WriteLine($"Player {PlayerIndex} walked right\n");
    //             battlefield->DrawBattlefield(5, 5);
    //         }
    //
    //         if (currentBox.yIndex > target->currentBox.yIndex)
    //         {
    //             battlefield->DrawBattlefield(5, 5);
    //             currentBox.occupied = false;
    //             battlefield->grids[currentBox.index] = currentBox;
    //             currentBox = battlefield->grids[(currentBox.index - battlefield->xLenght)];
    //             currentBox.occupied = true;
    //             battlefield->grids[currentBox.index] = currentBox;
    //             //Console.WriteLine($"PlayerB {PlayerIndex} walked up\n");
    //             return;
    //         }
    //         else if (currentBox.yIndex < target->currentBox.yIndex)
    //         {
    //             currentBox.occupied = true;
    //             battlefield->grids[currentBox.index] = currentBox;
    //             currentBox = battlefield->grids[currentBox.index + battlefield->xLenght];
    //             currentBox.occupied = false;
    //             battlefield->grids[currentBox.index] = currentBox;
    //             //Console.WriteLine($"Player {PlayerIndex} walked down\n");
    //             battlefield->DrawBattlefield(5, 5);
    //
    //             return;
    //         }
    //     }
    // }
}

bool Character::CheckCloseTargets(Grid* battlefield)
{
    return 0; //TODO: Change this.
}

void Character::Attack(Character* target)
{
}
