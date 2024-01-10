#include "header/PrintErrorMessageUser.hpp"

PrintErrorMessageUser::PrintErrorMessageUser() {}

void PrintErrorMessageUser::displayErrorMessage(std::string message)
{
    dataHandler.printMessage(message);
}
