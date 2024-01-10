#ifndef REQUERIMENTTYPEGAMETEST_H
#define REQUERIMENTTYPEGAMETEST_H

#include "RequerimentTypeGameAbstract.hpp"

class RequerimentTypeGameTest : public RequerimentTypeGameAbstract
{
    public:
        RequerimentTypeGameTest(std::shared_ptr<Game> game);
        int getUserTypeGame();
        bool checkUserTypeGame(int value);
        void isResultExpected();
    private:
        DataHandler dataHandler;
        std::shared_ptr<Game> _game;
};
#endif 
