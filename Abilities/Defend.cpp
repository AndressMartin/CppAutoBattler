#include "Defend.h"

namespace SpecialAbilities
{
    void Defend::Execute(Character& user, Character& target, Grid* battlefield)
    {
        std::cout << user.charName << " Blocks the next incoming damage. \n";
        target.attackBlocked = true;
    }
}