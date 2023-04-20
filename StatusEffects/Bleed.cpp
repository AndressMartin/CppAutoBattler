#include "Bleed.h"

#include "../Character.h"

namespace StatusEffects
{
    Bleed::Bleed(Character& owner) : BaseStatusEffect(owner) {}
    void Bleed::Proc()
    {
        if(counters != maxCounter)
        {
            counters++;
        }
        else
        {
            counters = 0;
            target.TakeDamage(bleedDamage);
        }
    }

    std::unique_ptr<BaseStatusEffect> Bleed::Clone(Character& newOwner) const
    {
        return std::make_unique<Bleed>(newOwner);
    }
}
