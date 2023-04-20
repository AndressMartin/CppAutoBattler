#include <memory>

#include "BaseSpecialAbility.h"
#include "ClearAilments.h"
#include "Heal.h"
#include "Intensify.h"
#include "Knockback.h"
#include "Multiattack.h"
#include "RunAndGun.h"
#include "Teleport.h"
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
            case Types::SpecialAbility::Teleport:
                return std::make_unique<Teleport>();
            case Types::SpecialAbility::RunAndGun:
                return std::make_unique<RunAndGun>();
            case Types::SpecialAbility::Intensify:
                return std::make_unique<Intensify>();
        }
        return nullptr;
    }
}