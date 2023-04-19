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
    CreateBattlefield();
    
    int currentTurn = 0;
    int numberOfPossibleTiles = grid->grids.size();

    SetPlayers();
    
    AllocateCharacter(playerCharacter);
    AllocateCharacter(enemyCharacter);
    grid->DrawBattlefield();
    StartTurn();
}

BattleField::~BattleField() {
    delete allPlayers;
}

void BattleField::CreateBattlefield()
{
    int x = 0;
    int y = 0;
    cout << "Insert the number of rows" << endl;
    cin >> x;
    cout << "Insert the number of collumns" << endl;
    cin >> y;
    grid = new Grid(x, y);
}

void BattleField::SetPlayers()
{
    allPlayers = new list<Character*>();
    const int classChoice = GetPlayerChoice();
    CreatePlayerCharacter(classChoice);
    CreateEnemyCharacter();
    
    enemyCharacter->target = playerCharacter;
    playerCharacter->target = enemyCharacter;
    allPlayers->push_back(playerCharacter);
    allPlayers->push_back(enemyCharacter);
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
    Classes::CharacterClass playerclass = static_cast<Classes::CharacterClass>(classIndex);
    cout << "Player Class Choice: " << Classes::StringifyCharacterClass[playerclass] << endl;

    playerCharacter = new Character(playerclass);
    
    cout << playerCharacter->health << endl << playerCharacter->baseDamage << endl << playerCharacter->playerIndex << endl; //TODO: Debugging
}

void BattleField::CreateEnemyCharacter()
{
    int classIndex = Utils::GetRandomInt(0, 3);
    Classes::CharacterClass enemyClass = static_cast<Classes::CharacterClass>(classIndex);
    cout << "Enemy Class Choice: " << Classes::StringifyCharacterClass[enemyClass] << endl;
    
    enemyCharacter = new Character(enemyClass);

    cout << enemyCharacter->health << endl << enemyCharacter->baseDamage << endl << enemyCharacter->playerIndex << endl; //TODO: Debugging
}

void BattleField::StartTurn()
{
    for (std::list<Character*>::iterator it = allPlayers->begin(); it != allPlayers->end(); ++it)
    {
        Character* character = *it;
        character->StartTurn(grid);
    }

    currentTurn++;
    HandleTurn();
}

void BattleField::HandleTurn()
{
    //TODO: Restore this after fixing the error
    if (playerCharacter->health == 0)
    {
        return;
    }
    else if (enemyCharacter->health == 0)
    {
        printf("\n");
    
        // endgame?
    
        printf("\n");
    
        return;
    }
    else
    {
        printf("Press anything to continue to next turn.\n");
        string input;
        cin >> input;
        printf("\n");
    
        StartTurn();
    }
}

void BattleField::AllocateCharacter(Character* player)
{
    std::vector<std::vector<Types::GridBox*>>* myGrid {&grid->grids};
    const int randomRow = Utils::GetRandomInt_MaxExclusive(0, myGrid->size());
    const int randomCol = Utils::GetRandomInt_MaxExclusive(0, (*myGrid)[randomRow].size());
    Types::GridBox* randomLocation = grid->grids[randomRow][randomCol];
    if (!randomLocation->occupied)
    {
        playerCurrentLocation = randomLocation;
        randomLocation->occupied = player;
        player->currentBox = randomLocation;
        return;
    }
    AllocateCharacter(player);
}