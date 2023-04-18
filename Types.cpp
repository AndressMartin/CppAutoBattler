#include "Types.h"

std::ostream& operator<<(std::ostream& os, const Types::CharacterClass& characterClass)
{
    switch (characterClass)
    {
        case Types::CharacterClass::Paladin:
            os << "PALADIN";
            break;
        case Types::CharacterClass::Warrior:
            os << "WARRIOR";
            break;
        case Types::CharacterClass::Archer:
            os << "ARCHER";
            break;
        case Types::CharacterClass::Cleric:
            os << "CLERIC";
            break;
        default:
            os << "UNKNOWN";
            break;
    }
    return os;
}

const char* Types::CharacterClass_ToString[] =
{
    STRINGIFY(Paladin),
    STRINGIFY(Warrior),
    STRINGIFY(Cleric),
    STRINGIFY(Archer)
};