#include "header/RequerimentBoardSizeUser.hpp"

RequerimentBoardSizeUser::RequerimentBoardSizeUser() {}

std::pair<int, int> RequerimentBoardSizeUser::getUserBoardSize()
{
    Language &languageInstance = Language::getInstance();
    int numberRows;
    int numberColumns;
    dataHandler.printMessage(languageInstance.getMessage(Messages::askNumberRows));

    do
    {
        numberRows = dataHandler.promptInteger();
    } while (!checkUserBoardSize(numberRows));
    
    dataHandler.printMessage(languageInstance.getMessage(Messages::askNumberColumns));
    do
    {
        numberColumns = dataHandler.promptInteger();
    } while (!checkUserBoardSize(numberColumns));

    return std::pair<int, int>(numberRows, numberColumns);
}

bool RequerimentBoardSizeUser::checkUserBoardSize(int value)
{
    Language &languageInstance = Language::getInstance();
    if(value >= 3)
    {
        return true;
    }
    dataHandler.printMessage(languageInstance.getMessage(Messages::invalidDimension));
    return false;
}

void RequerimentBoardSizeUser::isExpectedResult(){}
