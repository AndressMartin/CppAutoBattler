#include <iostream>
#include "BaseSpecialAbility.h"
#include "../Character.h"

class Character;

namespace SpecialAbilities
{
    class Defend : public BaseSpecialAbility
    {
    public:
        void Execute(Character& user, Character& target, Grid* battlefield) override;
    };
}