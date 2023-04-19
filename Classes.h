#pragma once

#include <map>
#include "Types.h"

namespace Classes
{
    struct ClassAttributes
    {
        float health;
        float baseDamage;
        float damageMultiplier;
    };

    class ClassDatabase
    {
    public:
        ClassDatabase();

        const ClassAttributes& GetAttributes(Types::CharacterClass characterClass) const;

    private:
        std::map<Types::CharacterClass, ClassAttributes> classAttributes;
    };
}
