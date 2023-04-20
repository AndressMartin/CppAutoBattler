#include <memory>

#include "BaseSpecialAbility.h"
#include "Defend.h"
#include "Knockback.h"
#include "../Types.h"

namespace SpecialAbilities
{
    std::unique_ptr<BaseSpecialAbility> CreateSpecialAbility(Types::SpecialAbility abilityType)
    {
        switch (abilityType)
        {
            case Types::SpecialAbility::Knockback:
                return std::make_unique<Knockback>();
            case Types::SpecialAbility::Defend:
                return std::make_unique<Defend>();
            default:
                return nullptr;
        }
    }
}