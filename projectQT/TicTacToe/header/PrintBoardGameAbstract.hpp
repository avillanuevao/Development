#ifndef PRINTBOARDGAMEABSTRACT_H
#define PRINTBOARDGAMEABSTRACT_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "DataHandler.hpp"
#include "PlayerCharacter.hpp"
#include "Board.hpp"

class PrintBoardGameAbstract
{
    public:
        PrintBoardGameAbstract(){};
        virtual void displayBoardGame() = 0;
};
#endif 
