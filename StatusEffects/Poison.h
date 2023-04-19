#pragma once

#include "BaseStatusEffect.h"

namespace StatusEffects
{
    class Poison : public BaseStatusEffect {
    public:
        void Inflict(Character& target) override;
    };
}