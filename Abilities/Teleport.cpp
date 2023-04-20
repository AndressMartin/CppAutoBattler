#include <iostream>
#include "../Character.h"
#include "Teleport.h"

#include "../Utils.h"

namespace SpecialAbilities
{
    void Teleport::Execute(Character& user, Character& target, Grid* battlefield)
    {
        int battlefieldWidth = battlefield->GetWidth();
        int battlefieldHeight = battlefield->GetHeight();

        Types::GridBox* newBox;

        do
        {
            const int newX = Utils::GetRandomInt_MaxExclusive(0, battlefieldWidth);
            const int newY = Utils::GetRandomInt_MaxExclusive(0, battlefieldHeight);

            newBox = battlefield->GetGridBox(newX, newY);
        } while (newBox == nullptr || newBox->occupied);

        target.currentBox->occupied = nullptr;
        target.currentBox = newBox;
        newBox->occupied = &target;
        
        std::cout << user.charName << " causes " << target.charName << " to be teleported randomly! \n";
        battlefield->DrawBattlefield();
    }
}