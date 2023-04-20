#include <iostream>
#include "Curse.h"
#include "../Character.h"
#include "../Utils.h"

namespace StatusEffects
{
    Curse::Curse(Character& target) : BaseStatusEffect(target, {Types::ProcEvent::OnStartOfTurn}) {}
    void Curse::Proc()
    {
        if(target.isDead)
            return;
        int chance = Utils::GetRandomInt(0, 100);
        if(chance <= ghostChance)
        {
            std::cout << " ghosts gnaw at your soul... ";
            target.TakeDamage(curseDamage);
        }
    }

    std::unique_ptr<BaseStatusEffect> Curse::Clone(Character& newOwner) const
    {
        return std::make_unique<Curse>(newOwner);
    }
}
