#include "Classes.h"
#include <ostream>

namespace Classes
{
    ClassDatabase::ClassDatabase()
    {
        attributes[Paladin] = {120.0f, 14.0f, 1.0f, 7,'P'};
        attributes[Warrior] = {100.0f, 12.0f, 1.5f, 15,'X'};
        attributes[Cleric] = {150.0f, 6.0f, 1.0f, 5,'C'};
        attributes[Archer] = {60.0f, 10.0f, 2.0f, 28,')'};
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