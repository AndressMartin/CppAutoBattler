#include "Classes.h"
#include <ostream>

namespace Classes
{
    ClassDatabase::ClassDatabase()
    {
        attributes[Paladin] =
        {
            120,
            14,
            1.5f,
            7,
            'P'
        };
        attributes[Warrior] =
        {
            100,
            12,
            2.0f,
            15,
            'X'
        };
        attributes[Cleric] =
        {
            150,
            6,
            1.5f,
            5,
            'C'
        };
        attributes[Archer] =
        {
            65,
            10,
            2.5f,
            28,
            ')'
        };
        attributes[Mage] =
        {
            60,
            12,
            3.0f,
            12,
            '0'
        };
    }

    const ClassAttributes& ClassDatabase::GetAttributes(CharacterClass characterClass) const
    {
        return attributes.at(characterClass);
    }

    const char* StringifyCharacterClass[] =
    {
        STRINGIFY(Paladin),
        STRINGIFY(Warrior),
        STRINGIFY(Cleric),
        STRINGIFY(Archer),
        STRINGIFY(Mage),
    };
}