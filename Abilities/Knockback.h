#include "BaseSpecialAbility.h"

class Character;

namespace SpecialAbilities
{
    class Knockback : public BaseSpecialAbility
    {
    public:
        void Execute(Character& user, Character& target, Grid* battlefield) override;
    };
}