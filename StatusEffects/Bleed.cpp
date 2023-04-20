#include <iostream>
#include "Bleed.h"
#include "../Character.h"

namespace StatusEffects
{
    Bleed::Bleed(Character& target) : BaseStatusEffect(target, {Types::ProcEvent::OnTookDamage}) {}
    void Bleed::Proc()
    {
        if(target.isDead)
            return;
        if(counter != maxCounter)
        {
            counter++;
            std::cout << target.charName << " bleeds with each blow...\n";
        }
        else
        {
            std::cout << target.charName << " takes bleed damage! ";
            counter = 0;
            target.TakeDamage(bleedDamage);
            target.RemoveStatusEffect(this);
        }
    }

    std::unique_ptr<BaseStatusEffect> Bleed::Clone(Character& newOwner) const
    {
        return std::make_unique<Bleed>(newOwner);
    }
}
