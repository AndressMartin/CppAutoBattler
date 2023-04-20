#include <iostream>
#include "../Character.h"
#include "Knockback.h"

namespace SpecialAbilities
{
    void Knockback::Execute(Character& user, Character& target, Grid* battlefield)
    {
        user.Attack();
        if(target.isDead)
            return;
        
        // Calculate the direction vector from the user to the target
        int directionX = target.currentBox->xIndex - user.currentBox->xIndex;
        int directionY = target.currentBox->yIndex - user.currentBox->yIndex;

        bool canMoveTarget = target.CanWalk(battlefield, directionX, directionY);

        if (canMoveTarget)
        {
            std::cout << target.charName << " is knocked back! \n";
            target.WalkTo(battlefield, directionX, directionY, &target);
            battlefield->DrawBattlefield();
        }
    }
}
