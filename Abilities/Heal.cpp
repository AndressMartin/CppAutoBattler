#include <iostream>
#include "../Character.h"
#include "Heal.h"

namespace SpecialAbilities
{
    void Heal::Execute(Character& user, Character& target, Grid* battlefield)
    {
        user.Heal(user.baseDamage * 2);
    }
}
