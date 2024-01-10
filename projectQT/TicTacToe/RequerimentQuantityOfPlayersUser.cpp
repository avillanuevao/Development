#include "header/RequerimentQuantityOfPlayersUser.hpp"

RequerimentQuantityOfPlayersUser::RequerimentQuantityOfPlayersUser() {}

int RequerimentQuantityOfPlayersUser::getUserQuantityOfPlayers()
{
    Language &languageInstance = Language::getInstance();
    int numberPlayers;
    do
    {
        dataHandler.printMessage(languageInstance.getMessage(Messages::askNumberPlayers));
        numberPlayers = dataHandler.promptInteger();
    } while (!checkUserQuantityOfPlayers(numberPlayers));
    
    return numberPlayers;
}

bool RequerimentQuantityOfPlayersUser::checkUserQuantityOfPlayers(int value)
{
    Language &languageInstance = Language::getInstance();
    if(value >= 2)
    {
        return true;
    }
    dataHandler.printMessage(languageInstance.getMessage(Messages::invalidNumberPlayers));
    return false;
}

void RequerimentQuantityOfPlayersUser::isResultExpected()
{

}
