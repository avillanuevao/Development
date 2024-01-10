#ifndef REQUERIMENTBOARDSIZEABSTRACT_H
#define REQUERIMENTBOARDSIZEABSTRACT_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "DataHandler.hpp"
#include "Language.hpp"
#include "Board.hpp"

class RequerimentBoardSizeAbstract
{
    public:
        RequerimentBoardSizeAbstract(){};
        virtual std::pair<int, int> getUserBoardSize() = 0;
        virtual bool checkUserBoardSize(int value) = 0;
        virtual void isExpectedResult() = 0;
};
#endif 
