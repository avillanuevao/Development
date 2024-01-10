#ifndef GAMETYPESELECTOR_H
#define GAMETYPESELECTOR_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <memory>
#include "Board.hpp"
#include "Game.hpp"
#include "RequerimentTypeGameUser.hpp"

class GameTypeInitializer
{
    public:
        GameTypeInitializer(std::shared_ptr<Game> game, std::shared_ptr<RequerimentTypeGameAbstract> requerimentTypeGame);
        void gameTypeInitializerExecute();
    private:
        std::shared_ptr<Game> _game;
        std::shared_ptr<RequerimentTypeGameAbstract> _requerimentTypeGame;
        int getGameTypeFormView();
        void setGameTypeInModel(int userTypeGame);
};
#endif 


