#ifndef REQUERIMENTTYPEGAMEABSTRACT_H
#define REQUERIMENTTYPEGAMEABSTRACT_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "DataHandler.hpp"
#include "Language.hpp"
#include "Game.hpp"

class RequerimentTypeGameAbstract
{
    public:
        RequerimentTypeGameAbstract(){};
        virtual int getUserTypeGame() = 0;
        virtual bool checkUserTypeGame(int value) = 0;
        virtual void isResultExpected() = 0;
};
#endif 
