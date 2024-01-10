#include "header/GameBoardInitializer.hpp"

GameBoardInitializer::GameBoardInitializer(std::shared_ptr<Game> game, std::shared_ptr<Board> board, std::shared_ptr<PrintBoardGameAbstract> printBoardGame, std::shared_ptr<RequerimentBoardSizeAbstract> requerimentBoardSize)
{
    _game = game;
    _board = board;
    _printBoardGame = printBoardGame;
    _requerimentBoardSize = requerimentBoardSize;
}

std::pair<int, int> GameBoardInitializer::getBoardDimensionFormView()
{
    std::pair<int, int> boardDimension = _requerimentBoardSize->getUserBoardSize();
    return boardDimension;
}

void GameBoardInitializer::setBoardDimensionInModel(std::pair<int, int> boardDimension)
{
    _board->setBoardDimension(boardDimension.first, boardDimension.second);
    _requerimentBoardSize->isExpectedResult();
}

void GameBoardInitializer::initBoardGame()
{
    _board->initBoardGame();
}

void GameBoardInitializer::printBoardGame()
{
    _printBoardGame->displayBoardGame();
}

void GameBoardInitializer::gameBoardInitializerExecute()
{
    auto dimensionFormView = getBoardDimensionFormView();
    setBoardDimensionInModel(dimensionFormView);
    initBoardGame();
    printBoardGame();
}
