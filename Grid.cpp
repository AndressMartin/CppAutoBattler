#include "Grid.h"
#include "Types.h"


Grid::Grid(const int lines, const int columns)
    : grids(lines, std::vector<Types::GridBox*>(columns)), xLength(lines), yLength(columns)
{
    std::cout << grids.size() << '\n';
    std::cout << grids[0].size() << '\n';
    for (int i = 0; i < xLength; i++)
    {
        for (int j = 0; j < yLength; j++)
        {
            auto newBox = new Types::GridBox(i, j, false, columns * i + j);
            grids[i][j] = newBox;
            // Console.Write($"{newBox.Index}\n");
        }
    }
}

Grid::~Grid()
= default;

void Grid::DrawBattlefield()
{
    for (int i = 0; i < grids.size(); i++)
    {
        for (int j = 0; j < grids[0].size(); j++)
        {
            if (grids[i][j]->occupied)
            {
                std::cout << "[X]\t";
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