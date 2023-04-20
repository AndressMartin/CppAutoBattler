#pragma once
#include "BaseSpecialAbility.h"

class Character;

namespace SpecialAbilities
{
    class Heal : public BaseSpecialAbility
    {
    public:
        void Execute(Character& user, Character& target, Grid* battlefield) override;
    };
}