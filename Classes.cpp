#include "Classes.h"
#include <ostream>

namespace Classes
{
    ClassDatabase::ClassDatabase()
    {
        attributes[Paladin] = {120.0f, 14.0f, 1.4f, 7,'P'};
        attributes[Warrior] = {100.0f, 12.0f, 1.8f, 15,'X'};
        attributes[Cleric] = {150.0f, 6.0f, 1.4f, 5,'C'};
        attributes[Archer] = {65.0f, 10.0f, 2.4f, 28,')'};
        attributes[Mage] = {60.0f, 12.0f, 2.8f, 12, '0'};
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