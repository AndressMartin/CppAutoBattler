#include "Grid.h"
#include "BattleField.h"
#include "Types.h"
#include "Character.h"
#include <iostream>
#include "BattleField.h"
#include <list>
#include <string>

using namespace std;

BattleField::BattleField()
{
    grid = new Grid(5, 5);
    allPlayers = new list<Character>();
    int currentTurn = 0;
    int numberOfPossibleTiles = grid->grids.size();
    Setup();
}

void BattleField::Setup()
{
    GetPlayerChoice();
}

void BattleField::GetPlayerChoice()
{
    //asks for the player to choose between for possible classes via console.
    printf("Choose Between One of this Classes:\n");

    printf("[1] Paladin, [2] Warrior, [3] Cleric, [4] Archer");
    //store the player choice in a variable
    std::string choice;

    std::getline(std::cin, choice);

    cin >> choice;
    switch ((choice))
    {
    case "1":
        CreatePlayerCharacter(choice);
        break;
    case "2":
        CreatePlayerCharacter(choice);
        break;
    case "3":
        CreatePlayerCharacter(choice);
        break;
    case "4":
        CreatePlayerCharacter(choice);
        break;
    default:
        GetPlayerChoice();
        break;
    }
}

void BattleField::CreatePlayerCharacter(int classIndex)
{
    auto characterClass = (Types::CharacterClass*)classIndex;
    printf("Player Class Choice: {characterClass}");

    playerCharacter = std::make_shared<Character>(characterClass);

    playerCharacter->health = 100;
    playerCharacter->baseDamage = 20;
    playerCharacter->playerIndex = 0;

    CreateEnemyCharacter();
}

void BattleField::CreateEnemyCharacter()
{
    //randomly choose the enemy class and set up vital variables

    int randomInteger = GetRandomInt(1, 4);
    auto enemyClass = (Types::CharacterClass)randomInteger;
    printf("Enemy Class Choice: {enemyClass}");
    enemyCharacter = new Character(enemyClass);
    enemyCharacter->Health = 100;
    playerCharacter->baseDamage = 20;
    playerCharacter->playerIndex = 1;
    StartGame();
}

void BattleField::StartGame()
{
    //populates the character variables and targets
    enemyCharacter->target = playerCharacter;
    playerCharacter->target = enemyCharacter;
    allPlayers->push_back(playerCharacter);
    allPlayers->push_back(enemyCharacter);
    AlocatePlayers();
    StartTurn();
}

void BattleField::StartTurn()
{
    if (currentTurn == 0)
    {
        //AllPlayers.Sort();  
    }

    for (std::list<Character>::iterator it = allPlayers->begin(); it != allPlayers->end(); ++it)
    {
        it->StartTurn(grid);
    }

    currentTurn++;
    HandleTurn();
}

void BattleField::HandleTurn()
{
    if (playerCharacter->health == 0)
    {
        return;
    }
    else if (enemyCharacter->Health == 0)
    {
        printf("\n");

        // endgame?

        printf("\n");

        return;
    }
    else
    {
        printf("\n");
        printf("Click on any key to start the next turn...\n");
        printf("\n");

        //TODO
        //ConsoleKeyInfo key = Console.ReadKey();
        StartTurn();
    }
}

int BattleField::GetRandomInt(int min, int max)
{
    int index = GetRandomInt(min, max);
    return index;
}

void BattleField::AlocatePlayers()
{
    AlocatePlayerCharacter();
}

void BattleField::AlocatePlayerCharacter()
{
    int random = 0;
    auto lFront = grid->grids.begin();
    advance(lFront, random);
    Types::GridBox* randomLocation = &*lFront;

    if (!randomLocation->occupied)
    {
        //Types::GridBox* PlayerCurrentLocation = RandomLocation;
        playerCurrentLocation = &*lFront;
        lFront->occupied = true;
        playerCharacter->currentBox = *lFront;
        AlocateEnemyCharacter();
    }
    else
    {
        AlocatePlayerCharacter();
    }
}

void BattleField::AlocateEnemyCharacter()
{
    int random = 24;
    auto lFront = grid->grids.begin();
    advance(lFront, random);
    Types::GridBox* randomLocation = &*lFront;

    if (!randomLocation->occupied)
    {
        enemyCurrentLocation = &*lFront;
        lFront->occupied = true;
        enemyCharacter->currentBox = *lFront;
        grid->drawBattlefield(5, 5);
    }
    else
    {
        AlocateEnemyCharacter();
    }
}
