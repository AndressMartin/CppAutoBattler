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
    ~BattleField();
    Grid* grid;
    Types::GridBox* playerCurrentLocation;
    Types::GridBox* enemyCurrentLocation;
    list<Character*>* allPlayers;
    Character* playerCharacter;
    Character* enemyCharacter;
    int currentTurn;
    int numberOfPossibleTiles;

    void CreateBattlefield();
    void DisplayClassDescriptions();
    void SetPlayers();
    bool IsValidClassChoice(int choice, int classesAmount);
    int GetPlayerChoice();
    void CreatePlayerCharacter(int classIndex);
    void CreateEnemyCharacter();
    void HandleTurn();
    void HandleTurnEnd();
    void AllocateCharacter(Character* player);
};
