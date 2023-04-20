#include "StatusEffectFactory.h"
#include "Bleed.h"
#include "Curse.h"
#include "Fear.h"
#include "Poison.h"
#include "../Character.h"

using namespace Types;

namespace StatusEffects
{
    std::unique_ptr<BaseStatusEffect> CreateStatusEffect(StatusEffect effectType, Character& owner)
    {
        switch (effectType)
        {
        case StatusEffect::Bleeding:
            return std::make_unique<Bleed>(owner);
        case StatusEffect::Poisoned:
            return std::make_unique<Poison>(owner);
        case StatusEffect::Cursed:
            return std::make_unique<Curse>(owner);
        case StatusEffect::Fearful:
            return std::make_unique<Fear>(owner);
        default:
            return nullptr;
        }
    }
}
