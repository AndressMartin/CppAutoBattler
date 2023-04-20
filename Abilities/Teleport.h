#pragma once
#include "BaseSpecialAbility.h"

class Character;

namespace SpecialAbilities
{
    class Teleport : public BaseSpecialAbility
    {
    public:
        void Execute(Character& user, Character& target, Grid* battlefield) override;
    };
}