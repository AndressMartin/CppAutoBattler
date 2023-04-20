#pragma once

#define STRINGIFY( name ) #name

class Character;

namespace Types
{
    struct GridBox
    {
        int xIndex;
        int yIndex;
        Character* occupied;
        int index;

        GridBox(const int x, const int y, Character* occupied, const int index)
        : xIndex(x), yIndex(y), occupied(occupied), index(index)
        {}

        bool operator==(const GridBox& other) const
        {
            return xIndex == other.xIndex && yIndex == other.yIndex && occupied == other.occupied && index == other.index;
        }
    };
    
    enum class StatusEffect
    {
        Poisoned,
        Bleeding,
        Cursed,
        Fearful,
        Burning,
        Frozen,
    };

    enum class ProcEvent
    {
        OnSuccessfulAttack,
        OnAboutToAttack,
        OnTookDamage,
        OnStartOfTurn,
        OnEndOfTurn,
    };

    enum class SpecialAbility
    {
        Knockback,
        Heal,
        Teleport,
        ClearAilments,
        Multiattack,
        RunAndGun,
        Intensify,
    };
    
    extern const char* StringifyStatusEffect[];
}