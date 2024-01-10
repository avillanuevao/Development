#ifndef REQUERIMENTQUANTITYOFPLAYERSABSTRACT_H
#define REQUERIMENTQUANTITYOFPLAYERSABSTRACT_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "DataHandler.hpp"
#include "Language.hpp"
#include "Game.hpp"

class RequerimentQuantityOfPlayersAbstract
{
    public:
        RequerimentQuantityOfPlayersAbstract(){};
        virtual int getUserQuantityOfPlayers() = 0;
        virtual bool checkUserQuantityOfPlayers(int value) = 0;
        virtual void isResultExpected() = 0;
};
#endif 
