#pragma once

#include "BaseStatusEffect.h"

namespace StatusEffects
{
    class Bleed : public BaseStatusEffect {
    public:
        void Inflict(Character& target) override;
    };
}