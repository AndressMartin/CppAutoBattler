#pragma once

class Character; //Forward declaration to avoid cyclical references with Character.h

class Types
{
public:
    struct GridBox
    {
        int xIndex;
        int yIndex;
        Character* occupied;
        int index;

        GridBox(const int x, const int y, Character* occupied, const int index)
        : xIndex(x), yIndex(y), occupied(occupied), index(index)
        {
        }

        bool operator==(const GridBox& other) const
        {
            return xIndex == other.xIndex && yIndex == other.yIndex && occupied == other.occupied && index == other.index;
        }
    };

    enum StatusEffect
    {
        Poisoned,
        Bleeding,
        Cursed,
        Fearful,
        Confused,
        Burning,
        Frozen,
    };
};
