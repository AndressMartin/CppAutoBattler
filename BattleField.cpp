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

    SetPlayers();
    
    AllocateCharacter(playerCharacter);
    AllocateCharacter(enemyCharacter);
    grid->DrawBattlefield();
    HandleTurn();
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
    int classChoice = 0;
    bool validChoice = false;
    int classesAmount = Classes::GetCharacterClassCount();
    do
    {
        cout << "Choose Between One of these Classes:\n";
        for (int i = 0; i < classesAmount; ++i)
        {
            cout << "[" << i + 1 << "] " << Classes::StringifyCharacterClass[i];
            if (i < classesAmount - 1)
            {
                cout << ", ";
            }
        }

        cout << "\n";
        cin >> classChoice;
        classChoice--;

        validChoice = IsValidClassChoice(classChoice, classesAmount);
    }
    while (!validChoice);
    return classChoice;
}

bool BattleField::IsValidClassChoice(int choice, int classesAmount)
{
    if (cin.fail() || choice < 0 || choice >= classesAmount)
    {
        cout << "Invalid input. Please try again.\n";
        cin.clear(); // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore newline
        return false;
    }
    return true;
}

void BattleField::CreatePlayerCharacter(int classIndex)
{
    const auto playerclass = static_cast<Classes::CharacterClass>(classIndex);
    cout << "Player Class Choice: " << Classes::StringifyCharacterClass[playerclass] << endl;

    playerCharacter = new Character(playerclass);
    playerCharacter->charName = "Player";
}

void BattleField::CreateEnemyCharacter()
{
    int classIndex = Utils::GetRandomInt(0, 3);
    Classes::CharacterClass enemyClass = static_cast<Classes::CharacterClass>(classIndex);
    cout << "Enemy Class Choice: " << Classes::StringifyCharacterClass[enemyClass] << endl;
    
    enemyCharacter = new Character(enemyClass);
    enemyCharacter->charName = "AI";
}

void BattleField::HandleTurn()
{
    cout << "----- TURN " << ++currentTurn << " -----\n";
    for (std::list<Character*>::iterator it = allPlayers->begin(); it != allPlayers->end(); ++it)
    {
        Character* character = *it;
        character->StartTurn(grid);
        cout << '\n';
    }

    HandleTurnEnd();
}

void BattleField::HandleTurnEnd()
{
    if (playerCharacter->isDead)
    {
        cout << "You lost! :(\nTry again! PS: Paladin is kinda broken!";
        return;
    }
    if (enemyCharacter->isDead)
    {
        cout << "You won! :]\n";
        cout << "\n\n";
        return;
    }
    
    cout << "Press Enter to continue to next turn.\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any remaining input in the buffer
    cin.get();
    cout << "\n\n";
    HandleTurn();
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