#include <iostream>
#include "Poison.h"
#include "../Character.h"

namespace StatusEffects
{
    Poison::Poison(Character& target) : BaseStatusEffect(target, {Types::ProcEvent::OnEndOfTurn}) {}
    void Poison::Proc()
    {
        if(target.isDead)
            return;
        std::cout << "Poison chips away at " << target.charName << "'s health... ";
        target.TakeDamage(poisonDamage);
        if(counter < maxCounter)
            counter++;
        else
            target.RemoveStatusEffect(this);
    }
    std::unique_ptr<BaseStatusEffect> Poison::Clone(Character& newOwner) const
    {
        return std::make_unique<Poison>(newOwner);
    }
}