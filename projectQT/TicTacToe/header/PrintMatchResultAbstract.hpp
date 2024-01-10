#ifndef PRINTMATCHRESULTABSTRACT_H
#define PRINTMATCHRESULTABSTRACT_H

#include <iostream>
#include <string>
#include <vector>
#include "DataHandler.hpp"

class PrintMatchResultAbstract
{
    public:
        PrintMatchResultAbstract(){};
        virtual void displayMatchResult(std::string message) = 0;
};
#endif 
