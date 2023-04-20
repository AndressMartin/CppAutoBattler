#include <iostream>
#include "../Character.h"
#include "Intensify.h"

namespace SpecialAbilities
{
    void Intensify::Execute(Character& user, Character& target, Grid* battlefield)
    {
        std::cout << user.charName << " intensifies their power, increasing base damage. ";
        user.damageModifiers += 8;
        user.Attack();
    }
}
