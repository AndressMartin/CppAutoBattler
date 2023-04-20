﻿#include <memory>

#include "BaseSpecialAbility.h"
#include "../Types.h"

namespace SpecialAbilities
{
    std::unique_ptr<BaseSpecialAbility> SpecialAbilities::CreateSpecialAbility(Types::SpecialAbility abilityType)
    {
        switch (abilityType)
        {
            // case Types::SpecialAbility::Knockback:
            //     return std::make_unique<Knockback>();
            // case Types::SpecialAbility::StrongAttack:
            //     return std::make_unique<StrongAttack>();
            //     // ... other abilities ...
            default:
                return nullptr;
        }
    }
}