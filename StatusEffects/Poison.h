#pragma once

#include "BaseStatusEffect.h"

namespace StatusEffects
{
    class Poison : public BaseStatusEffect
    {
public:
        const int poisonDamage = 6;
        const int maxCounter = 10;
        int counter = 0;
        Poison(Character& target);
        void Proc() override;
        std::unique_ptr<BaseStatusEffect> Clone(Character& newOwner) const override;
    };
}