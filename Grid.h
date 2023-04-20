#pragma once
#include <Vector>
#include "Types.h"

class Grid
{
public:
    Grid(int lines, int columns);
    ~Grid();

    std::vector<std::vector<Types::GridBox*>> grids;

    Types::GridBox* GetGridBox(int x, int y);
    int GetWidth() const;
    int GetHeight() const;
    void DrawBattlefield();

private:
    int xLength;
    int yLength;
};
