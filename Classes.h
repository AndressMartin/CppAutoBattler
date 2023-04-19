#pragma once

#include <map>
#include <string>
#define STRINGIFY( name ) #name

namespace Classes
{
    struct ClassAttributes
    {
        int health;
        int baseDamage;
        float critMultiplier;
        int critChance;
        char icon;
        std::string description;
    };

    enum CharacterClass
    {
        Paladin,
        Warrior,
        Cleric,
        Archer,
        Mage,
        CharacterClassCount, //Easy way to get the size of the enum
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

    inline int GetCharacterClassCount()
    {
        return CharacterClassCount;
    }
}
