#include "Grid.h"
#include "Types.h"


Grid::Grid(int lines, int columns)
{
    xLenght = lines;
    yLength = columns;
    //Console.WriteLine("The battle field has been created\n");
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            auto newBox = new Types::GridBox(i, j, false, (columns * i + j));
            // grids.insert(grids.end(), newBox); //TODO: Restore these lines
            //Console.Write($"{newBox.Index}\n");
        }
    }
    //drawBattlefield(Lines, Columns);
}

Grid::~Grid()
{
}

void Grid::DrawBattlefield(int lines, int columns)
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            // Types::GridBox* currentGrid = new Types::GridBox(); //TODO: Restore these lines
            // if (currentGrid->occupied)
            // {
            //     //if()
            //     printf("[X]\t");
            // }
            // else
            // {
            //     printf("[ ]\t");
            // }
        }
        printf("\n");
    }
    printf("\n");
}
