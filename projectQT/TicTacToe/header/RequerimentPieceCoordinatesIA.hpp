#ifndef REQUERIMENTPIECECOORDINATESIA_H
#define REQUERIMENTPIECECOORDINATESIA_H

#include "RequerimentPieceCoordinatesAbstract.hpp"
#include <cstdlib>
#include <ctime>
#include <memory>
#include <thread>
#include <chrono>
#include <utility>
#include "Board.hpp"

class RequerimentPieceCoordinatesIA : public RequerimentPieceCoordinatesAbstract
{
    public:
        RequerimentPieceCoordinatesIA(std::shared_ptr<Board> board);
        std::pair<int, int> getUserPieceCoordinates() override;
        void isResultExpected(std::string message) override;

    private:
        DataHandler dataHandler;
        std::shared_ptr<Board> _board;
        int counterBug = 0;
        std::pair<size_t, size_t> moveDecisorRowColumn();
        std::pair<size_t, size_t> randomGenerator(size_t row, bool isGenerateRow);
        std::pair<bool, size_t> willWin(PlayerCharacter::playerCharacter player);
        std::pair<bool, size_t> possibleWin(PlayerCharacter::playerCharacter player);
};
#endif 
