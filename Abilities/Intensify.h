#include "BaseSpecialAbility.h"

class Character;

namespace SpecialAbilities
{
    class Intensify : public BaseSpecialAbility
    {
    public:
        void Execute(Character& user, Character& target, Grid* battlefield) override;
    };
}