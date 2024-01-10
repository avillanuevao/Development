#ifndef PRINTERRORMESSAGEUSER_H
#define PRINTERRORMESSAGEUSER_H

#include "PrintErrorMessageAbstract.hpp"

class PrintErrorMessageUser : public PrintErrorMessageAbstract
{
    public:
        PrintErrorMessageUser();
        void displayErrorMessage(std::string message) override;
    private:
        DataHandler dataHandler;
};
#endif 
