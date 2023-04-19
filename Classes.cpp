#include "Classes.h"

using namespace Classes;

ClassDatabase::ClassDatabase()
{
    classAttributes[Types::Paladin] = {100.0f, 10.0f, 1.0f};
    classAttributes[Types::Warrior] = {120.0f, 8.0f, 1.2f};
    classAttributes[Types::Cleric] = {80.0f, 5.0f, 1.5f};
    classAttributes[Types::Archer] = {60.0f, 15.0f, 0.8f};
}

const ClassAttributes& ClassDatabase::GetAttributes(Types::CharacterClass characterClass) const
{
    return classAttributes.at(characterClass);
}