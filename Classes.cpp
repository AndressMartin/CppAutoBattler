#include "Classes.h"
#include "Types.h"

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
            1,
            'P',
            {Types::StatusEffect::Fearful},
            30,
            "Can choose to heal themselves and choose to defend. Can inflict \"fearful\" status, causing opponent to heal you instead.",
        };
        attributes[Warrior] =
        {
            100,
            12,
            2.0f,
            15,
            1,
            'X',
            {Types::StatusEffect::Bleeding},
            50,
            "Has good chance to hit twice and can choose to defend. Can inflict bleeding. Gets stronger as life depletes.",
        };
        attributes[Cleric] =
        {
            150,
            6,
            1.5f,
            5,
            1,
            'C',
            {Types::StatusEffect::Cursed},
            30,
            "Can choose to heal themselves. Can inflict \"cursed\" status, making ghosts appear to hit the target.",
        };
        attributes[Archer] =
        {
            70,
            10,
            2.5f,
            28,
            3,
            ')',
            {Types::StatusEffect::Poisoned},
            40,
            "Can hit from three squares away. High evasion rate. Can inflict poison.",
        };
        attributes[Mage] =
        {
            60,
            12,
            3.0f,
            12,
            2,
            '0',
            {Types::StatusEffect::Burning,Types::StatusEffect::Frozen,},
            30,
            "Can hit from two squares away, and conjure meteors. Can inflict a random status.",
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