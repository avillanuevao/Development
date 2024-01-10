#include "header/PrintBoardGameUser.hpp"
PrintBoardGameUser::PrintBoardGameUser(std::shared_ptr<Board> board){
    _board = board;
}

void PrintBoardGameUser::displayBoardGame()
{
    std::string message;
    std::string valueBoard;
    for (int x = 0; x < _board->getBoardDimension().numberRows; x++)
    {
        message = "|";
        dataHandler.printMessage(message);
        for (int y = 0; y < _board->getBoardDimension().numberColumns; y++)
        {  
            valueBoard = _playerCharacter->enumToString(_board->getInMutableBoardGame()[x][y]);
            message = valueBoard + "|";
            dataHandler.printMessage(message);
        }    
        message = "\n";
        dataHandler.printMessage(message);
    }
}
