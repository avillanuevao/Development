#include "header/GameTypeInitializer.hpp"

GameTypeInitializer::GameTypeInitializer(std::shared_ptr<Game> game, std::shared_ptr<RequerimentTypeGameAbstract> requerimentTypeGame)
{
    _game = game;
    _requerimentTypeGame = requerimentTypeGame;
}

void GameTypeInitializer::gameTypeInitializerExecute()
{
    int userTypeGame = getGameTypeFormView();
    setGameTypeInModel(userTypeGame);
}

int GameTypeInitializer::getGameTypeFormView()
{
    int userTypeGame = _requerimentTypeGame->getUserTypeGame();
    return userTypeGame;
}
void GameTypeInitializer::setGameTypeInModel(int userTypeGame)
{
    _game->setTypeGame(userTypeGame);
}
