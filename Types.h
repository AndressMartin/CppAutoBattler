#pragma once
class Types
{
public:
    struct GridBox
    {
        int xIndex;
        int yIndex;
        bool occupied;
        int index;

        GridBox(const int x, const int y, const bool occupied, const int index)
        {
            xIndex = x;
            yIndex = y;
            this->occupied = occupied;
            this->index = index;
        }

        bool operator==(const GridBox& other) const
        {
            return xIndex == other.xIndex && yIndex == other.yIndex && occupied == other.occupied && index == other.index;
        }
    };

    enum CharacterClass
    {
        Paladin = 1,
        Warrior = 2,
        Cleric = 3,
        Archer = 4
    };
};
