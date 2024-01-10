#include "header/PrintMatchResultUser.hpp"

PrintMatchResultUser::PrintMatchResultUser() {}

void PrintMatchResultUser::displayMatchResult(std::string message)
{
    dataHandler.printMessage(message);
}
