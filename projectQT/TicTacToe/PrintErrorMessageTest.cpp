#include "header/PrintErrorMessageTest.hpp"

PrintErrorMessageTest::PrintErrorMessageTest() {}

void PrintErrorMessageTest::displayErrorMessage(std::string message)
{
    dataHandler.printMessage(message);
}
