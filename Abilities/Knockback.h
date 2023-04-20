#include <iostream>
#include "BaseSpecialAbility.h"
#include "../Character.h"

class Character;

namespace SpecialAbilities
{
    // Knockback.h
    class Knockback : public BaseSpecialAbility
    {
    public:
        void Execute(Character& user, Character& target) override;
    };

    // Knockback.cpp
    void Knockback::Execute(Character& user, Character& target)
    {
        std::cout << "Triggered Knockback";
        user.Attack();
        //Knockback target;
    }
}