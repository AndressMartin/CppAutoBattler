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

    void DrawBattlefield();
    Types::GridBox* GetGridBox(int x, int y);
    int GetWidth() const;
    int GetHeight() const;
};
