#pragma once

#include <map>
#define STRINGIFY( name ) #name

namespace Classes
{
    struct ClassAttributes
    {
        float health;
        float baseDamage;
        float damageMultiplier;
        char icon;
    };

    enum CharacterClass
    {
        Paladin,
        Warrior,
        Cleric,
        Archer,
    };

    class ClassDatabase
    {
    public:
        ClassDatabase();

        const ClassAttributes& GetAttributes(CharacterClass characterClass) const;

    private:
        std::map<CharacterClass, ClassAttributes> attributes;
    };

    extern const char* StringifyCharacterClass[];
}
