#pragma once

class Grid;
class Character;

namespace SpecialAbilities
{
    class BaseSpecialAbility
    {
    public:
        virtual ~BaseSpecialAbility() = default;

        // The method to execute the special ability
        virtual void Execute(Character& user, Character& target, Grid* battlefield) = 0;
    };
}
