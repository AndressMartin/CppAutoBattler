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
    cout << "Entering Setup()\n"; // Add this line
    GetPlayerChoice();
}

void BattleField::GetPlayerChoice()
{
    int choice = 0;
    bool validChoice = false;
    
    do
    {
        cout << "Choose Between One of these Classes:\n";
        cout << "[1] Paladin, [2] Warrior, [3] Cleric, [4] Archer\n";
        cin >> choice;

        // Check if input is valid
        if (cin.fail())
        {
            cout << "Invalid input. Please try again.\n";
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore newline
            //Clear console();
        }
        else
        {
            validChoice = true;
        }
    }
    while (!validChoice);

    cout << "It worked\n"; //TODO: Remove this
}

void BattleField::CreatePlayerCharacter(int classIndex)
{
    auto characterClass = (Types::CharacterClass*)classIndex;
    cout << "Player Class Choice: {characterClass}";

    //TODO: Restore this after fixing the error
    // playerCharacter = make_shared<Character>(characterClass);
    //
    // playerCharacter->health = 100;
    // playerCharacter->baseDamage = 20;
    // playerCharacter->playerIndex = 0;
    //
    // CreateEnemyCharacter();
}

void BattleField::CreateEnemyCharacter()
{
    //randomly choose the enemy class and set up vital variables

    int randomInteger = GetRandomInt(1, 4);
    auto enemyClass = (Types::CharacterClass)randomInteger;
    cout << "Enemy Class Choice: {enemyClass}";
    //TODO: Restore this after fixing the error
    // enemyCharacter = new Character(enemyClass);
    // enemyCharacter->Health = 100;
    // playerCharacter->baseDamage = 20;
    // playerCharacter->playerIndex = 1;
    StartGame();
}

void BattleField::StartGame()
{
    //TODO: Restore this after fixing the error
    //populates the character variables and targets
    // enemyCharacter->target = playerCharacter;
    // playerCharacter->target = enemyCharacter;
    // allPlayers->push_back(playerCharacter);
    // allPlayers->push_back(enemyCharacter);
    AllocatePlayers();
    StartTurn();
}

void BattleField::StartTurn()
{
    // if (currentTurn == 0)
    // {
    //     //AllPlayers.Sort();  
    // }

    for (std::list<Character>::iterator it = allPlayers->begin(); it != allPlayers->end(); ++it)
    {
        it->StartTurn(grid);
    }

    currentTurn++;
    HandleTurn();
}

void BattleField::HandleTurn()
{
    //TODO: Restore this after fixing the error
    // if (playerCharacter->health == 0)
    // {
    //     return;
    // }
    // else if (enemyCharacter->Health == 0)
    // {
    //     printf("\n");
    //
    //     // endgame?
    //
    //     printf("\n");
    //
    //     return;
    // }
    // else
    // {
    //     printf("\n");
    //     printf("Click on any key to start the next turn...\n");
    //     printf("\n");
    //
    //     //TODO
    //     //ConsoleKeyInfo key = Console.ReadKey();
    //     StartTurn();
    // }
}

//TODO: Can be part of a UTILS class
int BattleField::GetRandomInt(int min, int max)
{
    int index = GetRandomInt(min, max);
    return index;
}

void BattleField::AllocatePlayers()
{
    AllocatePlayerCharacter();
}

void BattleField::AllocatePlayerCharacter()
{
    int random = 0; //TODO: Not being used
    auto lFront = grid->grids.begin();
    advance(lFront, random);
    Types::GridBox* randomLocation = &*lFront;

    if (!randomLocation->occupied)
    {
        //Types::GridBox* PlayerCurrentLocation = RandomLocation;
        playerCurrentLocation = &*lFront;
        lFront->occupied = true;
        playerCharacter->currentBox = *lFront;
        AllocateEnemyCharacter();
    }
    else
    {
        AllocatePlayerCharacter();
    }
}

void BattleField::AllocateEnemyCharacter()
{
    //TODO: Restore this after fixing the error
    // int random = 24; //TODO: Not being used
    // auto lFront = grid->grids.begin();
    // advance(lFront, random);
    // Types::GridBox* randomLocation = &*lFront;
    //
    // if (!randomLocation->occupied)
    // {
    //     enemyCurrentLocation = &*lFront;
    //     lFront->occupied = true;
    //     enemyCharacter->currentBox = *lFront;
    //     grid->drawBattlefield(5, 5);
    // }
    // else
    // {
    //     AllocateEnemyCharacter();
    // }
}
