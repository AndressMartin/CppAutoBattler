#pragma once

#include <memory>
#include "BaseStatusEffect.h"

namespace StatusEffects
{
    class Freeze : public BaseStatusEffect
    {
    public:
        const int maxCounter = 4;
        int chanceUnfreeze = 10;
        int counter = 0;
        
        Freeze(Character& target);
        void Proc() override;
        std::unique_ptr<BaseStatusEffect> Clone(Character& newOwner) const override;
    };
}