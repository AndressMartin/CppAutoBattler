#include <memory>

#include "BaseSpecialAbility.h"
#include "ClearAilments.h"
#include "Heal.h"
#include "Knockback.h"
#include "Multiattack.h"
#include "../Types.h"

namespace SpecialAbilities
{
    std::unique_ptr<BaseSpecialAbility> CreateSpecialAbility(Types::SpecialAbility abilityType)
    {
        switch (abilityType)
        {
            case Types::SpecialAbility::Knockback:
                return std::make_unique<Knockback>();
            case Types::SpecialAbility::Heal:
                return std::make_unique<Heal>();
            case Types::SpecialAbility::ClearAilments:
                return std::make_unique<ClearAilments>();
            case Types::SpecialAbility::Multiattack:
                return std::make_unique<Multiattack>();
            default:
                return nullptr;
        }
    }
}