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

    std::ostream& operator<<(std::ostream& os, const CharacterClass& characterClass)
    {
        switch (characterClass)
        {
        case CharacterClass::Paladin:
            os << "PALADIN";
            break;
        case CharacterClass::Warrior:
            os << "WARRIOR";
            break;
        case CharacterClass::Archer:
            os << "ARCHER";
            break;
        case CharacterClass::Cleric:
            os << "CLERIC";
            break;
        default:
            os << "UNKNOWN";
            break;
        }
        return os;
    }

    const char* StringifyCharacterClass[] =
    {
        STRINGIFY(Paladin),
        STRINGIFY(Warrior),
        STRINGIFY(Cleric),
        STRINGIFY(Archer),
    };
}