#include "Classes.h"
#include <ostream>

namespace Classes
{
    ClassDatabase::ClassDatabase()
    {
        attributes[Paladin] = {100.0f, 10.0f, 1.0f, 'T'};
        attributes[Warrior] = {120.0f, 8.0f, 1.2f, 'X'};
        attributes[Cleric] = {140.0f, 5.0f, 0.8f, 'C'};
        attributes[Archer] = {60.0f, 15.0f, 1.5f, ')'};
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
    };
}