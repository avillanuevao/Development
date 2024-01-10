#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "Language.hpp"

class DataHandler
{
    public:
        DataHandler();
        void printMessage(const std::string& message);
        int promptInteger();
};

#endif 