#pragma once

#include <memory>
#include "BaseStatusEffect.h"

namespace StatusEffects
{
    class Curse : public BaseStatusEffect
    {
    public:
        const int curseDamage = 10;
        const int ghostChance = 80;
        
        Curse(Character& target);
        void Proc() override;
        std::unique_ptr<BaseStatusEffect> Clone(Character& newOwner) const override;
    };
}