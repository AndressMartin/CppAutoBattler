#pragma once

class Grid;
class Character;

namespace SpecialAbilities
{
    class BaseSpecialAbility
    {
    public:
        virtual ~BaseSpecialAbility() = default;

        virtual void Execute(Character& user, Character& target, Grid* battlefield) = 0;
        virtual bool CanUse(Character& user, Character& target) { return true; }
    };
}
