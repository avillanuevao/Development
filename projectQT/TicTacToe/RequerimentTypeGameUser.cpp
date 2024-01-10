#include "header/RequerimentTypeGameUser.hpp"

RequerimentTypeGameUser::RequerimentTypeGameUser(std::shared_ptr<Game> game) {
    _game = game;
}

int RequerimentTypeGameUser::getUserTypeGame()
{
    Language &languageInstance = Language::getInstance();
    int typeGame = 0;
    if(_game->getNumberOfPlayers() == 2)
    {
        do
        {
            dataHandler.printMessage(languageInstance.getMessage(Messages::askTypeGame));
            typeGame = dataHandler.promptInteger();
        } while (!checkUserTypeGame(typeGame));
    }

    return typeGame;
}

bool RequerimentTypeGameUser::checkUserTypeGame(int value)
{
    Language &languageInstance = Language::getInstance();
    if(value == 0 || value == 1)
    {
        return true;
    }
    dataHandler.printMessage(languageInstance.getMessage(Messages::invalidTypeGame));
    return false;
}

void RequerimentTypeGameUser::isResultExpected(){}
