#include "Poison.h"
#include "../Character.h"

namespace StatusEffects
{
    Poison::Poison(Character& owner) : BaseStatusEffect(owner) {}
    void Poison::Proc()
    {
        
    }
    std::unique_ptr<BaseStatusEffect> Poison::Clone(Character& newOwner) const
    {
        return std::make_unique<Poison>(newOwner);
    }
}
