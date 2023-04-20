#include <iostream>
#include "../Character.h"
#include "Multiattack.h"

namespace SpecialAbilities
{
    void Multiattack::Execute(Character& user, Character& target, Grid* battlefield)
    {
        std::cout << target.charName << " attacks twice! \n";
        user.Attack();
        user.Attack();
    }
}
