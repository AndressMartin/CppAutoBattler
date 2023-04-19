#pragma once
#include <Vector>
#include "Types.h"

class Grid
{
public:
    Grid(int lines, int columns);
    ~Grid();

    std::vector<std::vector<Types::GridBox*>> grids;

    int xLength;
    int yLength;

    // prints the matrix that indicates the tiles of the battlefield
    // void DrawBattlefield(int lines, int columns);
    void DrawBattlefield();
};
