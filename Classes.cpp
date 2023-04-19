#include "Classes.h"
#include <ostream>

namespace Classes
{
    ClassDatabase::ClassDatabase()
    {
        attributes[Paladin] = {100.0f, 10.0f, 1.0f, 7,'T'};
        attributes[Warrior] = {120.0f, 15.0f, 1.2f, 15,'X'};
        attributes[Cleric] = {140.0f, 5.0f, 0.8f, 5,'C'};
        attributes[Archer] = {60.0f, 10.0f, 1.8f, 18,')'};
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