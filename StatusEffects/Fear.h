#pragma once

#include <memory>
#include "BaseStatusEffect.h"

namespace StatusEffects
{
    class Fear : public BaseStatusEffect
    {
    public:
        const float healAmount = 0.75f;
        const int maxCounter = 3;
        int counter = 0;
        
        Fear(Character& target);
        void Proc() override;
        std::unique_ptr<BaseStatusEffect> Clone(Character& newOwner) const override;
    };
}