#ifndef PRINTMATCHRESULTUSER_H
#define PRINTMATCHRESULTUSER_H

#include "PrintMatchResultAbstract.hpp"

class PrintMatchResultUser : public PrintMatchResultAbstract
{
    public:
        PrintMatchResultUser();
        void displayMatchResult(std::string message);
    private:
        DataHandler dataHandler;
};
#endif 
