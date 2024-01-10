#ifndef PRINTBOARDGAMETEST_H
#define PRINTBOARDGAMETEST_H

#include "PrintBoardGameAbstract.hpp"

class PrintBoardGameTest : public PrintBoardGameAbstract
{
    public:
        PrintBoardGameTest();
        void displayBoardGame() override;
    private:
        DataHandler dataHandler;
        std::shared_ptr<PlayerCharacter> _playerCharacter;
};
#endif 
