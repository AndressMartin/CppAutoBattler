#pragma once

#include <memory>
#include "BaseStatusEffect.h"

namespace StatusEffects
{
    class Burn : public BaseStatusEffect
    {
    public:
        const int maxDamage = 10;
        const int initialDamage = 3;
        const int burnIncrement = 3;
        int burnDamage = initialDamage;

        Burn(Character& target);
        void Proc() override;
        std::unique_ptr<BaseStatusEffect> Clone(Character& newOwner) const override;
    };
}