#include "header/RequerimentPieceCoordinatesIA.hpp"

RequerimentPieceCoordinatesIA::RequerimentPieceCoordinatesIA(std::shared_ptr<Board> board)
{
    _board = board;
}

void RequerimentPieceCoordinatesIA::isResultExpected(std::string message){}

std::pair<int, int> RequerimentPieceCoordinatesIA::getUserPieceCoordinates()
{
    std::pair<size_t, size_t> decisorRowColumn = moveDecisorRowColumn();
    int row = decisorRowColumn.first;
    int column = decisorRowColumn.second;
    counterBug = 0;
    return std::pair<size_t, size_t>(row, column);
}

std::pair<size_t, size_t> RequerimentPieceCoordinatesIA::moveDecisorRowColumn()
{
    auto winIA = willWin(PlayerCharacter::playerCharacter::o);
    auto winPlayer = willWin(PlayerCharacter::playerCharacter::x);
    auto possibleIA = possibleWin(PlayerCharacter::playerCharacter::o);

    if(winIA.first)
    {
        auto coordinates = randomGenerator(winIA.second, false);
        return std::pair<size_t, size_t>(coordinates.first, coordinates.second);
    }
    if(winPlayer.first)
    {
        auto coordinates = randomGenerator(winPlayer.second, false);
        return std::pair<size_t, size_t>(coordinates.first, coordinates.second);
    }
    if(possibleIA.first)
    {
        auto coordinates = randomGenerator(possibleIA.second, false);
        return std::pair<size_t, size_t>(coordinates.first, coordinates.second);
    }
    auto coordinates = randomGenerator(winIA.second, true);
    return std::pair<size_t, size_t>(coordinates.first, coordinates.second);

}

std::pair<bool, size_t> RequerimentPieceCoordinatesIA::possibleWin(PlayerCharacter::playerCharacter player)
{
    std::vector<std::vector<PlayerCharacter::playerCharacter>> boardInmutable = _board->getMutableBoardGame();
    int numberRows = _board->getBoardDimension().numberRows;
    int numberColumns = _board->getBoardDimension().numberColumns;

    PlayerCharacter::playerCharacter piece;
    bool isPossible = false;
    int xPosition = 0;
    int counterX = 0;

    for (int x = 0; x < numberRows; x++)
    {
        for (int y = 0; y < numberColumns; y++)
        {
            piece = boardInmutable[x][y];

            if(piece == !player && piece != PlayerCharacter::playerCharacter::none)
            {
                counterX++;
            }
        }
        if(counterX == 0)
        {
            isPossible = counterX == 0;
            xPosition = x;
            return std::pair<bool, size_t>(isPossible, xPosition);
        }
        counterX = 0;
    }
   return std::pair<bool, size_t>(isPossible, xPosition);
}

std::pair<bool, size_t> RequerimentPieceCoordinatesIA::willWin(PlayerCharacter::playerCharacter player)
{
    std::vector<std::vector<PlayerCharacter::playerCharacter>> boardInmutable = _board->getMutableBoardGame();
    int numberRows = _board->getBoardDimension().numberRows;
    int numberColumns = _board->getBoardDimension().numberColumns;

    PlayerCharacter::playerCharacter piece;
    bool isPossible = false;
    int xPosition = 0;
    int counterX = 0;
    int counterO = 0;
    for (int x = 0; x < numberRows; x++)
    {
        for (int y = 0; y < numberColumns; y++)
        {
            piece = boardInmutable[x][y];

            if(piece == player)
            {
                counterX++;
            }else if(piece == PlayerCharacter::playerCharacter::none)
            {
                counterO++;
            }

            if(counterX == 2)
            {
                isPossible = counterO == 1;
                xPosition = x;
                return std::pair<bool, size_t>(isPossible, xPosition);
            }
        }
        counterX = 0;
        counterO = 0;
    }
   return std::pair<bool, size_t>(isPossible, xPosition);
}

std::pair<size_t, size_t> RequerimentPieceCoordinatesIA::randomGenerator(size_t row, bool isGenerateRow)
{
    std::vector<std::vector<PlayerCharacter::playerCharacter>> boardInmutable = _board->getMutableBoardGame();
    size_t column;
    size_t fakeRow = row;
    do
    {
        if(isGenerateRow)
        {
            fakeRow = std::rand() % 3;
            column = std::rand() % 3;
        }else
        {
            column = std::rand() % 3;
            counterBug++;
        }
    }while((boardInmutable[fakeRow][column] == 0 || boardInmutable[fakeRow][column] == 1) && counterBug <= 4555555);
    return std::pair<size_t, size_t>(fakeRow, column);
}
