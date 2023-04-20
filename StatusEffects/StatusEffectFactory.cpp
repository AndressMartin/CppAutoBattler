#include "StatusEffectFactory.h"
#include "Bleed.h"
#include "Burn.h"
#include "Curse.h"
#include "Fear.h"
#include "Freeze.h"
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
            case StatusEffect::Burning:
                return std::make_unique<Burn>(owner);
            case StatusEffect::Frozen:
                return std::make_unique<Freeze>(owner);
        }
        return nullptr;
    }
}
