#pragma once

#include <memory>
class Character; // Forward declaration of Character

namespace StatusEffects
{
    class BaseStatusEffect
    {
public:
        BaseStatusEffect(Character& target);
        virtual void Proc() = 0;
        void Inflict(Character& target);
        virtual std::unique_ptr<BaseStatusEffect> Clone(Character& newOwner) const = 0;
        Character& target;
    };
}