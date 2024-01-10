#include "header/Board.hpp"

Board::Board(){}

void Board::initBoardGame()
{
    boardGame.resize(boardDimensionStored.numberRows);
    for (int x = 0; x < boardDimensionStored.numberRows; x++)
    {
        boardGame[x].resize(boardDimensionStored.numberColumns);
        for (int y = 0; y < boardDimensionStored.numberColumns; y++)
        {
            boardGame[x][y] = PlayerCharacter::playerCharacter::none;
        }    
    }
}

bool Board::isValidatedInputCoordinates(std::pair<int, int> userCoordinates)
{
    return (isInRange(userCoordinates) && isEmpty(userCoordinates));
}

bool Board::isWinnerDetected()
{
    return (isCompletedRow() || isCompletedColumn() || isCompletedDiagonalA() || isCompletedDiagonalB());
}

void Board::setBoardDimension(int numberRows, int numberColumns)
{
    boardDimensionStored.numberRows = numberRows;
    boardDimensionStored.numberColumns = numberColumns;
}   

const boardDimension Board::getBoardDimension()
{
    return boardDimensionStored;
}

std::vector<std::vector<PlayerCharacter::playerCharacter>>& Board::getMutableBoardGame()
{
    return boardGame;
}

const std::vector<std::vector<PlayerCharacter::playerCharacter>> Board::getInMutableBoardGame()
{
    return boardGame;
}

void Board::addBoardPiece(int coordinateX, int coordinateY, PlayerCharacter::playerCharacter playerOn)
{
    boardGame[coordinateX][coordinateY] = playerOn;
}

bool Board::isInRange(std::pair<int, int> userCoordinates)
{
    int coordenateX = userCoordinates.first;
    int coordenateY = userCoordinates.second;

    bool xInRange  = coordenateX >= 0 && coordenateX <= boardDimensionStored.numberRows;
    bool yInRange = coordenateY >= 0 && coordenateY <= boardDimensionStored.numberRows;

    return (xInRange && yInRange);
}

bool Board::isEmpty(std::pair<int, int> userCoordinates)
{
    int coordenateX = userCoordinates.first;
    int coordenateY = userCoordinates.second;

    return (boardGame[coordenateX][coordenateY] == PlayerCharacter::playerCharacter::none);
}

std::vector<PlayerCharacter::playerCharacter> Board::checkCombination(std::vector<PlayerCharacter::playerCharacter> boardCombination, int x, int y)
{
    if(!boardCombination.empty())
    {
        if(boardCombination[0] != boardGame[x][y])
        {
            boardCombination.clear();
        }
    }
    boardCombination.push_back(boardGame[x][y]);
    return boardCombination;
}

bool Board::isTicTacToe(std::vector<PlayerCharacter::playerCharacter> boardCombination)
{
    return (boardCombination.size() == 3 && boardCombination[0] != PlayerCharacter::playerCharacter::none);
}

bool Board::isCompletedRow()
{
    std::vector<PlayerCharacter::playerCharacter> boardCombination;
    for (int x = 0; x < boardDimensionStored.numberRows; x++) 
    {
        int y = 0;
        while (y < boardDimensionStored.numberColumns) 
        {
            boardCombination = checkCombination(boardCombination, x, y);
            if(isTicTacToe(boardCombination))
            {
                return true;
            }
            y++;
        }
        boardCombination.clear();
    }
    return false;
}

bool Board::isCompletedColumn()
{
    std::vector<PlayerCharacter::playerCharacter> boardCombination;
    for (int y = 0; y < boardDimensionStored.numberColumns; y++) {
        int x= 0;
        while (x < boardDimensionStored.numberRows) 
        {
            boardCombination = checkCombination(boardCombination, x, y);
            if(isTicTacToe(boardCombination))
            {
                return true;
            }
            x++;
        }
        boardCombination.clear();        
    }
    return false;
}

bool Board::isCompletedDiagonalA()
{
    std::vector<PlayerCharacter::playerCharacter> boardCombination;
    int y = 0;
    while (y < boardDimensionStored.numberColumns) 
    {
        boardCombination = checkCombination(boardCombination, y, y);
        if(isTicTacToe(boardCombination))
        {
            return true;
        }
        y++;
    }
    return false;
}

bool Board::isCompletedDiagonalB()
{
    std::vector<PlayerCharacter::playerCharacter> boardCombination;
    int primero = 0;
    int ultimo = boardDimensionStored.numberColumns - 1;

    int y = 0;
    while (y < boardDimensionStored.numberColumns) 
    {
        boardCombination = checkCombination(boardCombination, primero + y, ultimo - y);
        if(isTicTacToe(boardCombination))
        {
            return true;
        }
        y++;
    }
    return false;
}
