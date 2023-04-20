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
            {
                Types::SpecialAbility::Heal,
                Types::SpecialAbility::Knockback,
                Types::SpecialAbility::ClearAilments,
            },
            20,
            R"(Good health and base damage. Strong and consistent.
            Inflicts "fearful" status, causing opponent to heal you instead.
            Actions: "Heal", "Knockback" and "Clear Ailments".)",
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
            40,
            {
                Types::SpecialAbility::Knockback,
                Types::SpecialAbility::Multiattack,
            },
            30,
            R"(Aggressive and dependant on proccing their abilities. Can finish fights quickly.
            Inflicts "bleeding" status, causing opponent to suffer heavy damage from blows.
            Actions: "Knockback" and "Multiattack".)",
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
            {
                Types::SpecialAbility::Heal,
                Types::SpecialAbility::Intensify,
            },
            70,
            R"(Highest health and lowest damage, but can snowball out of control if left unchecked.
            Inflicts "cursed" status, causing opponent to be haunted by ghosts.
            Actions: "Heal" and "Intensify".)",
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
            {
                Types::SpecialAbility::RunAndGun,
                Types::SpecialAbility::Multiattack,
            },
            60,
            R"(Highly dependant on getting critical hits and multiattacks.
            Hits from three squares away and inflicts poison.
            Actions: "Run And Gun" and "Multiattack".)",
        };
        attributes[Mage] =
        {
            60,
            10,
            1.5f,
            12,
            2,
            '0',
            {
                Types::StatusEffect::Burning,
                Types::StatusEffect::Frozen,
            },
            30,
            {
                Types::SpecialAbility::Teleport,
                Types::SpecialAbility::Knockback,
            },
            50,
            R"(Lowest health in the game but lots of maneuvers to block incoming attack. Very random effects.
            Hits from two squares away and inflicts two magical status effects.
            Actions: "Teleport" and "Knockback".)",
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