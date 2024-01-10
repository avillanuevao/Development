#ifndef REQUERIMENTTYPEGAMEUSER_H
#define REQUERIMENTTYPEGAMEUSER_H

#include "RequerimentTypeGameAbstract.hpp"

class RequerimentTypeGameUser : public RequerimentTypeGameAbstract
{
    public:
        RequerimentTypeGameUser(std::shared_ptr<Game> game);
        int getUserTypeGame();
        bool checkUserTypeGame(int value);
        void isResultExpected();
    private:
        DataHandler dataHandler;
        std::shared_ptr<Game> _game;
};
#endif 
