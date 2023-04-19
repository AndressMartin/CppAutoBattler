#pragma once
#include "Character.h"
#include "Types.h"
#include <list>
#include <iostream>
#include "Grid.h"
using namespace std;

class BattleField
{
public:
    BattleField();

    Grid* grid;
    Types::GridBox* playerCurrentLocation;
    Types::GridBox* enemyCurrentLocation;
    list<Character>* allPlayers;
    Character* playerCharacter;
    Character* enemyCharacter;
    int currentTurn;
    int numberOfPossibleTiles;

    void CreateBattlefield();
    
    void SetPlayers();

    int GetPlayerChoice();

    void CreatePlayerCharacter(int classIndex);

    void CreateEnemyCharacter();

    void StartGame();

    void StartTurn();

    void HandleTurn();

    void AllocateCharacter(Character* player);
};
