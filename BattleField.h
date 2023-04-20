#pragma once
#include "Character.h"
#include <list>
#include "Grid.h"

class BattleField
{
public:
    BattleField();
    ~BattleField();
private:
    Grid* grid;
    std::list<Character*>* allPlayers;
    Character* playerCharacter;
    Character* enemyCharacter;
    int currentTurn;

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