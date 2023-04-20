#pragma once

#include <memory>
#include "BaseStatusEffect.h"

namespace StatusEffects
{
    class Bleed : public BaseStatusEffect
    {
public:
        const int maxCounter = 2;
        const int bleedDamage = 30;
        int counter = 0;
        Bleed(Character& target);
        void Proc() override;
        std::unique_ptr<BaseStatusEffect> Clone(Character& newOwner) const override;
    };
}