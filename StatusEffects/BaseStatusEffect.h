#pragma once

#include <memory>
#include <Vector>

#include "../Types.h"

class Character; // Forward declaration of Character

namespace StatusEffects
{
    class BaseStatusEffect
    {
    public:
        Character& target;
        std::vector<Types::ProcEvent> procEvents;
        
        BaseStatusEffect(Character& target, std::vector<Types::ProcEvent> events);
        virtual void Proc() = 0;
        virtual std::unique_ptr<BaseStatusEffect> Clone(Character& newOwner) const = 0;
        bool ShouldProcOnEvent(Types::ProcEvent event) const;
        void Inflict(Character& target);
    };
}