#pragma once

#include "../Types.h"
#include "BaseStatusEffect.h"
#include <memory>

namespace StatusEffects
{
    std::unique_ptr<BaseStatusEffect> CreateStatusEffect(Types::StatusEffect effectType, Character& owner);
}