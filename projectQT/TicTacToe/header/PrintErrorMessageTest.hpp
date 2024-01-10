#ifndef PRINTERRORMESSAGETEST_H
#define PRINTERRORMESSAGETEST_H

#include "PrintErrorMessageAbstract.hpp"

class PrintErrorMessageTest : public PrintErrorMessageAbstract
{
    public:
        PrintErrorMessageTest();
        void displayErrorMessage(std::string message) override;
    private:
        DataHandler dataHandler;
};
#endif 
