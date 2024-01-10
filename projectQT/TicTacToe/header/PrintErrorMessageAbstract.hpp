#ifndef PRINTERRORMESSAGEABSTRACT_H
#define PRINTERRORMESSAGEABSTRACT_H

#include <iostream>
#include <string>
#include <vector>
#include "DataHandler.hpp"

class PrintErrorMessageAbstract
{
    public:
        PrintErrorMessageAbstract(){};
        virtual void displayErrorMessage(std::string message) = 0;
};
#endif 
