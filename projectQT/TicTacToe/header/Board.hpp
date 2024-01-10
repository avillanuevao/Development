#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <ctime>
#include <chrono>
#include "PlayerCharacter.hpp"

struct boardDimension
{
    int numberRows;
    int numberColumns;
};

class Board
{
    public:
        Board();
        void initBoardGame();
        void setBoardDimension(int numberRows, int numberColumns);
        void addBoardPiece(int coordinateX, int coordinateY, PlayerCharacter::playerCharacter playerOn);
        bool isValidatedInputCoordinates(std::pair<int, int> userCoordinates);
        bool isWinnerDetected();
        std::vector<std::vector<PlayerCharacter::playerCharacter>>& getMutableBoardGame();
        const std::vector<std::vector<PlayerCharacter::playerCharacter>> getInMutableBoardGame();
        const boardDimension getBoardDimension();

    private:
        boardDimension boardDimensionStored;
        std::vector<std::vector<PlayerCharacter::playerCharacter>> boardGame;
        std::vector<PlayerCharacter::playerCharacter> checkCombination(std::vector<PlayerCharacter::playerCharacter> boardCombination, int x, int y);
        bool isTicTacToe(std::vector<PlayerCharacter::playerCharacter> boardCombination);
        bool isInRange(std::pair<int, int> userCoordinates);
        bool isEmpty(std::pair<int, int> userCoordinates);
        bool isCompletedRow();
        bool isCompletedColumn();
        bool isCompletedDiagonalA();
        bool isCompletedDiagonalB();
    
};
#endif 
