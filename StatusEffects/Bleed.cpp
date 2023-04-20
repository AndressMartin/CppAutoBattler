#include "Bleed.h"

#include <iostream>

#include "../Character.h"

namespace StatusEffects
{
    Bleed::Bleed(Character& owner) : BaseStatusEffect(owner) {}
    void Bleed::Proc()
    {
        if(counter != maxCounter)
        {
            counter++;
            std::cout << target.charName << " bleed counter " << counter <<"\n";
        }
        else
        {
            std::cout << target.charName << " takes bleed damage!\n";
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
