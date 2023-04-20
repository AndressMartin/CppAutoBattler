#pragma once
#include "BaseSpecialAbility.h"

class Character;

namespace SpecialAbilities
{
    class ClearAilments : public BaseSpecialAbility
    {
    public:
        void Execute(Character& user, Character& target, Grid* battlefield) override;
        bool CanUse(Character& user, Character& target) override;
    };
}