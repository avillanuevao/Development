#ifndef REQUERIMENTPIECECOORDINATESABSTRACT_H
#define REQUERIMENTPIECECOORDINATESABSTRACT_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "DataHandler.hpp"
#include "Language.hpp"

class RequerimentPieceCoordinatesAbstract
{
    public:
        RequerimentPieceCoordinatesAbstract(){};
        virtual std::pair<int, int> getUserPieceCoordinates() = 0;
        virtual void isResultExpected(std::string message) = 0;
};
#endif 
