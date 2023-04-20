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
        std::cout << "Poison chips away at " << target.charName << "'s health...\n";
        target.TakeDamage(poisonDamage);
    }
    std::unique_ptr<BaseStatusEffect> Poison::Clone(Character& newOwner) const
    {
        return std::make_unique<Poison>(newOwner);
    }
}