#include "header/ManageGame.hpp"

ManageGame::ManageGame(std::shared_ptr<Board> board, std::shared_ptr<Game> game, std::shared_ptr<PrintBoardGameAbstract> printBoardGame, std::shared_ptr<RequerimentPieceCoordinatesAbstract> requerimentPieceCoordinates, std::shared_ptr<RequerimentPieceCoordinatesAbstract> requerimentPieceCoordinatesIA,std::shared_ptr<PrintMatchResultAbstract> printMatchResult, std::shared_ptr<PrintErrorMessageAbstract> printErrorMessage)
{
    languageInstance = &Language::getInstance();
    _board = board;
    _game = game;
    _printBoardGame = printBoardGame;
    _printMatchResult = printMatchResult;
    _printErrorMessage = printErrorMessage;
    _requerimentPieceCoordinates.push_back(requerimentPieceCoordinates);
    _requerimentPieceCoordinates.push_back(requerimentPieceCoordinatesIA);
}

std::pair<int, int> ManageGame::getPieceCoordinatesFormView(int actualPlayer)
{
    //MAL -> NO puedo hacer referencia mediante enteros por un tipo de otra cosa -> Usar enum
    if(_game->getTypeGame() == 1)
    {
        return _requerimentPieceCoordinates[actualPlayer]->getUserPieceCoordinates();
    }
    return _requerimentPieceCoordinates[0]->getUserPieceCoordinates();

}

std::pair<int, int> ManageGame::getPieceCoordinates(int actualPlayer)
{
    bool isValidCoordinate;
    std::pair<int, int> userPieceCoordinates;
    do
    {
        userPieceCoordinates = getPieceCoordinatesFormView(actualPlayer);
        isValidCoordinate = _board->isValidatedInputCoordinates(userPieceCoordinates);

        if(_game->getTypeGame() == 1)
        {
            if(actualPlayer == 0)
            {
                if(!isValidCoordinate)
                {
                    _printErrorMessage->displayErrorMessage((*languageInstance).getMessage(Messages::invalidCoordinate));
                }
            }else if(actualPlayer == 1)
            {

            }
        }else
        {
            if(!isValidCoordinate)
            {
                _printErrorMessage->displayErrorMessage((*languageInstance).getMessage(Messages::invalidCoordinate));
            }
        }

    } while (!isValidCoordinate);
    std::cout << "getPieceCoordinates " << userPieceCoordinates.first << " " << userPieceCoordinates.second << std::endl;
    return userPieceCoordinates;
}

void ManageGame::placePieceOnBoard(std::pair<int, int> userPieceCoordinates, PlayerCharacter::playerCharacter actualPlayer)
{
    _board->addBoardPiece(userPieceCoordinates.first, userPieceCoordinates.second, actualPlayer);
}

void ManageGame::increaseGameNumber()
{
    _game->increaseGameNumber();
}

void ManageGame::printBoardGame()
{
    _printBoardGame->displayBoardGame();
}

bool ManageGame::checkGameStatus()
{
    return (_board->isWinnerDetected()) || (_game->getGameNumber() == _game->getMaxNumberGames());
}

void ManageGame::gameOverMessage(PlayerCharacter::playerCharacter actualPlayer)
{
    std::string winner;
    std::string message;
    if(_board->isWinnerDetected())
    {
        winner = _playerCharacter->enumToString(actualPlayer);
        message = (*languageInstance).getMessage(Messages::overWinner) + winner;
        _printMatchResult->displayMatchResult(message);
    }else
    {
        message = (*languageInstance).getMessage(Messages::overNoWinner);
        _printMatchResult->displayMatchResult(message);
    }
    _requerimentPieceCoordinates[0]->isResultExpected(message);
}

void ManageGame::piecePlacementControllerExecute()
{
    PlayerCharacter::playerCharacter actualPlayer;
    setMaxNumberGames();
    do
    {
        actualPlayer = _game->switchPlayer();
        auto pieceCoordinates = getPieceCoordinates(actualPlayer);
        placePieceOnBoard(pieceCoordinates, actualPlayer);
        increaseGameNumber();
        printBoardGame();
    } while (!checkGameStatus());
    gameOverMessage(actualPlayer);
}

void ManageGame::setMaxNumberGames()
{
    int dimensionBoard = _board->getBoardDimension().numberRows * _board->getBoardDimension().numberColumns;
    if (dimensionBoard % 2 == 0)
    {
        dimensionBoard -= 1;
    }
    _game->setMaxNumberGames(dimensionBoard);
}

int ManageGame::getMaxNumberGames()
{
    return _game->getMaxNumberGames();
}
