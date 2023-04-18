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
    shared_ptr<Character> playerCharacter;
    //Character* PlayerCharacter;
    shared_ptr<Character> enemyCharacter;
    int currentTurn;
    int numberOfPossibleTiles;


    void Setup();

    int GetPlayerChoice();

    void CreatePlayerCharacter(int classIndex);

    void CreateEnemyCharacter();

    void StartGame();

    void StartTurn();

    void HandleTurn();

    void AllocatePlayers();

    void AllocatePlayerCharacter();

    void AllocateEnemyCharacter();
};
