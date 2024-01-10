#ifndef PRINTBOARDGAMEUSER_H
#define PRINTBOARDGAMEUSER_H

#include "PrintBoardGameAbstract.hpp"

class PrintBoardGameUser : public PrintBoardGameAbstract
{
    public:
        PrintBoardGameUser(std::shared_ptr<Board> board);
        void displayBoardGame() override;
    private:
        DataHandler dataHandler;
        std::shared_ptr<Board> _board;
        std::shared_ptr<PlayerCharacter> _playerCharacter;
};
#endif 
