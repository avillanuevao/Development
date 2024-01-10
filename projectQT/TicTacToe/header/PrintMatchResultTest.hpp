#ifndef PRINTMATCHRESULTTEST_H
#define PRINTMATCHRESULTTEST_H

#include "PrintMatchResultAbstract.hpp"

class PrintMatchResultTest : public PrintMatchResultAbstract
{
    public:
        PrintMatchResultTest();
        void displayMatchResult(std::string message);
    private:
        DataHandler dataHandler;
};
#endif 
