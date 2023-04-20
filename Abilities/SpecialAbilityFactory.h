#include "BaseSpecialAbility.h"

namespace SpecialAbilities
{
    std::unique_ptr<BaseSpecialAbility> CreateSpecialAbility(Types::SpecialAbility abilityType);
}
