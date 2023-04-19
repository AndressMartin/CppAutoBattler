#pragma once

class Character; // Forward declaration of Character

namespace StatusEffects
{
    class BaseStatusEffect
    {
    public:
        virtual void Inflict(Character& target) = 0;
    };
}