#include <iostream>
#include "Burn.h"
#include "../Character.h"

namespace StatusEffects
{
    Burn::Burn(Character& target) : BaseStatusEffect(target, {Types::ProcEvent::OnEndOfTurn}) {}
    void Burn::Proc()
    {
        if(target.isDead)
            return;
        if(burnDamage < maxDamage)
        {
            std::cout << target.charName << " Burns away... ";
            target.TakeDamage(burnDamage);
            burnDamage+=burnIncrement;
        }
        if(burnDamage >= maxDamage)
        {
            burnDamage = initialDamage;
            target.RemoveStatusEffect(this);
        }
    }

    std::unique_ptr<BaseStatusEffect> Burn::Clone(Character& newOwner) const
    {
        return std::make_unique<Burn>(newOwner);
    }
}
