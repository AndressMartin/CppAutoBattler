#include <iostream>
#include <math.h>
#include "Fear.h"
#include "../Character.h"

namespace StatusEffects
{
    Fear::Fear(Character& target) : BaseStatusEffect(target, {Types::ProcEvent::OnAboutToAttack}) {}
    void Fear::Proc()
    {
        if(target.isDead)
            return;
        
        if(counter < maxCounter)
        {
            std::cout << target.charName << " fears attacking " << target.target->charName << ", healing them instead! ";
            target.target->Heal(ceil(target.baseDamage * healAmount));
            target.attackBlocked = true;
            counter++;
        }
        if(counter >= maxCounter)
            target.RemoveStatusEffect(this);
    }

    std::unique_ptr<BaseStatusEffect> Fear::Clone(Character& newOwner) const
    {
        return std::make_unique<Fear>(newOwner);
    }
}
