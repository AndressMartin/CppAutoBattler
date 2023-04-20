#pragma once

#include "BaseStatusEffect.h"

namespace StatusEffects
{
    class Poison : public BaseStatusEffect
    {
public:
        Poison(Character& target);
        void Proc() override;
        std::unique_ptr<BaseStatusEffect> Clone(Character& newOwner) const override;
    };
}