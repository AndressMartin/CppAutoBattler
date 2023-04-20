#include "StatusEffectFactory.h"
#include "Bleed.h"
#include "Poison.h"
#include "../Character.h"

namespace StatusEffects
{
    std::unique_ptr<BaseStatusEffect> CreateStatusEffect(Types::StatusEffect effectType, Character& owner)
    {
        switch (effectType)
        {
        case Types::StatusEffect::Bleeding:
            return std::make_unique<Bleed>(owner);
        case Types::StatusEffect::Poisoned:
            return std::make_unique<Poison>(owner);
        default:
            return nullptr;
        }
    }
}
