#include <iostream>
#include "../Character.h"
#include "RunAndGun.h"

namespace SpecialAbilities
{
    void RunAndGun::Execute(Character& user, Character& target, Grid* battlefield)
    {
        // Calculate the direction vector from the user to the target
        int directionX = user.currentBox->xIndex - target.currentBox->xIndex;
        int directionY = user.currentBox->yIndex - target.currentBox->yIndex;

        bool canMoveUser = user.CanWalk(battlefield, directionX, directionY);

        if (canMoveUser)
        {
            user.WalkTo(battlefield, directionX, directionY, &user);
            battlefield->DrawBattlefield();
            std::cout << user.charName << " steps back from danger, and shoots! ";
        }
        user.Attack();
    }
}
