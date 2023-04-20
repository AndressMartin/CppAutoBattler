#include <iostream>
#include <math.h>
#include "Freeze.h"
#include "../Character.h"
#include "../Utils.h"

namespace StatusEffects
{
    Freeze::Freeze(Character& target) : BaseStatusEffect(target, {Types::ProcEvent::OnStartOfTurn}) {}
    void Freeze::Proc()
    {
        if(target.isDead)
            return;
        int chance = Utils::GetRandomInt(0, 100);
        bool unfreeze = chance < chanceUnfreeze;
        if(!unfreeze)
            chanceUnfreeze += chanceUnfreeze;
        if(counter < maxCounter)
        {
            std::cout << target.charName << " is frozen and cannot act.\n";
            target.actionBlocked = true;
            counter++;
        }
        if(counter >= maxCounter || unfreeze)
        {
            counter = 0;
            target.RemoveStatusEffect(this);
        }
    }

    std::unique_ptr<BaseStatusEffect> Freeze::Clone(Character& newOwner) const
    {
        return std::make_unique<Freeze>(newOwner);
    }
}
