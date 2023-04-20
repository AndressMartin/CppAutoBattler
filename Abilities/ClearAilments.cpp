#include <iostream>
#include "../Character.h"
#include "ClearAilments.h"

namespace SpecialAbilities
{
    void ClearAilments::Execute(Character& user, Character& target, Grid* battlefield)
    {
        std::cout << user.charName << " will clear the body of curses and ailments.\n";
        // Store the pointers to status effects first
        std::vector<StatusEffects::BaseStatusEffect*> effectsToRemove;
        for (auto& effect : user.statusEffects_inflicted)
        {
            effectsToRemove.push_back(effect.get());
        }

        for (auto effect : effectsToRemove)
        {
            user.RemoveStatusEffect(effect);
        }
    }

    bool ClearAilments::CanUse(Character& user, Character& target)
    {
        return !user.statusEffects_inflicted.empty();
    }
}
