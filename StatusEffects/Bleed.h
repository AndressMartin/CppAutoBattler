#pragma once

#include <memory>
#include "BaseStatusEffect.h"

namespace StatusEffects
{
    class Bleed : public BaseStatusEffect
    {
public:
        const int bleedDamage = 25;
        const int maxCounter = 2;
        int counter = 0;
        
        Bleed(Character& target);
        void Proc() override;
        std::unique_ptr<BaseStatusEffect> Clone(Character& newOwner) const override;
    };
}