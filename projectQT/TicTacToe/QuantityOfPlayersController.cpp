#include "header/QuantityOfPlayersController.hpp"

QuantityOfPlayersController::QuantityOfPlayersController(std::shared_ptr<Board> board, std::shared_ptr<Game> game, std::shared_ptr<RequerimentQuantityOfPlayersAbstract> requerimentQuantityOfPlayers)
{
    _board = board;
    _game = game;
    _requerimentQuantityOfPlayers = requerimentQuantityOfPlayers;
}

int QuantityOfPlayersController::calculateMaxNumberPlayers()
{
    int rows = _board->getBoardDimension().numberRows;
    int columns = _board->getBoardDimension().numberColumns;
    int availableCharacterSize = _game->getAvailableCharacterSize();
    int boardSquareSize;

    if(rows >= columns)
    {
        boardSquareSize = ((rows * columns)/rows) - 1;
    }
    else
    {
        boardSquareSize = ((rows * columns)/columns) - 1;
    }
    return (std::min(boardSquareSize, availableCharacterSize));
}

void QuantityOfPlayersController::setMaxNumberPlayersInModel()
{
    _game->setMaxNumberOfPlayers(calculateMaxNumberPlayers());
}

void QuantityOfPlayersController::setNumberPlayersInModel()
{
    int userNumberPlayers;
    do
    {
        userNumberPlayers = _requerimentQuantityOfPlayers->getUserQuantityOfPlayers();
    } while ((userNumberPlayers < _game->getMinNumberOfPlayers()) || (userNumberPlayers > _game->getMaxNumberOfPlayers()));
    _game->setNumberOfPlayers(userNumberPlayers);
    _requerimentQuantityOfPlayers->isResultExpected();
}

void QuantityOfPlayersController::addPlayers()
{
    _game->initPlayers();
}

void QuantityOfPlayersController::quantityOfPlayersControllerExecute()
{
        calculateMaxNumberPlayers();
        setMaxNumberPlayersInModel();
        setNumberPlayersInModel();
        addPlayers();

}
