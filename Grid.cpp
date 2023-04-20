#include <iostream>
#include "Grid.h"
#include "Types.h"
#include "Character.h"

Grid::Grid(const int lines, const int columns)
    : grids(lines, std::vector<Types::GridBox*>(columns)), xLength(columns), yLength(lines)
{
    for (int j = 0; j < xLength; j++)
    {
        for (int i = 0; i < yLength; i++)
        {
            auto newBox = new Types::GridBox(j, i, nullptr, columns * j + i);
            grids[i][j] = newBox;
        }
    }
}

Grid::~Grid()= default;

void Grid::DrawBattlefield()
{
    for (int i = 0; i < grids.size(); i++)
    {
        for (int j = 0; j < grids[0].size(); j++)
        {
            if (grids[i][j]->occupied)
            {
                std::cout << "[" << grids[i][j]->occupied->icon << "]\t";
            }
            else
            {
                std::cout << "[ ]\t";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

Types::GridBox* Grid::GetGridBox(int x, int y)
{
    if (y >= yLength || x >= xLength || x < 0 || y < 0)
    {
        return nullptr;
    }

    return grids[y][x];
}

int Grid::GetWidth() const
{
    return xLength;
}

int Grid::GetHeight() const
{
    return yLength;
}