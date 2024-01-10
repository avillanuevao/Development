#ifndef GAMEBOARDINITIALIZE_H
#define GAMEBOARDINITIALIZE_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <memory>
#include "Game.hpp"
#include "Board.hpp"
#include "RequerimentBoardSizeAbstract.hpp"
#include "PrintBoardGameAbstract.hpp"

class GameBoardInitializer
{
    public:
        GameBoardInitializer(std::shared_ptr<Game> _game, std::shared_ptr<Board> board, std::shared_ptr<PrintBoardGameAbstract> printBoardGame, std::shared_ptr<RequerimentBoardSizeAbstract> requerimentBoardSize);
        void gameBoardInitializerExecute();
    private:
        std::shared_ptr<Game> _game;
        std::shared_ptr<Board> _board;
        std::shared_ptr<RequerimentBoardSizeAbstract> _requerimentBoardSize;
        std::shared_ptr<PrintBoardGameAbstract> _printBoardGame;
        
        std::pair<int, int> getBoardDimensionFormView();
        void setBoardDimensionInModel(std::pair<int, int> boardDimension);
        void initBoardGame();
        void printBoardGame();
};
#endif 
