#include "Grid.h"
#include "BattleField.h"
#include "Types.h"
#include "Character.h"
#include "Utils.h"
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
    const int choice = GetPlayerChoice();
    CreatePlayerCharacter(choice);
    CreateEnemyCharacter();
    // StartGame();
}

int BattleField::GetPlayerChoice()
{
    int choice = 0;
    bool validChoice = false;
    
    do
    {
        cout << "Choose Between One of these Classes:\n";
        cout << "[1] Paladin, [2] Warrior, [3] Cleric, [4] Archer\n";
        cin >> choice;
        choice--;
        // Check if input is valid
        if (cin.fail())
        {
            cout << "Invalid input. Please try again.\n";
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore newline
        }
        else
        {
            validChoice = true;
        }
    }
    while (!validChoice);
    return choice;
}

void BattleField::CreatePlayerCharacter(int classIndex)
{
    Types::CharacterClass playerclass = static_cast<Types::CharacterClass>(classIndex);
    cout << "Player Class Choice: " << Types::CharacterClass_ToString[playerclass] << endl;

    playerCharacter = make_shared<Character>(playerclass);
    
    playerCharacter->health = 100;
    playerCharacter->baseDamage = 20;
    playerCharacter->playerIndex = 0;
    
    cout << playerCharacter->health << endl << playerCharacter->baseDamage << endl << playerCharacter->playerIndex << endl; //TODO: Debugging
}

void BattleField::CreateEnemyCharacter()
{
    int classIndex = Utils::GetRandomInt(0, 3);
    Types::CharacterClass enemyClass = static_cast<Types::CharacterClass>(classIndex);
    cout << "Enemy Class Choice: " << Types::CharacterClass_ToString[enemyClass] << endl;
    
    enemyCharacter = make_shared<Character>(enemyClass);
    
    enemyCharacter->health = 100;
    enemyCharacter->baseDamage = 20;
    enemyCharacter->playerIndex = 1;

    cout << enemyCharacter->health << endl << enemyCharacter->baseDamage << endl << enemyCharacter->playerIndex << endl; //TODO: Debugging
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