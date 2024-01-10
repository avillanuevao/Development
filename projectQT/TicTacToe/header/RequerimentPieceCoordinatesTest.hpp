#ifndef REQUERIMENTPIECECOORDINATESTEST_H
#define REQUERIMENTPIECECOORDINATESTEST_H

#include "RequerimentPieceCoordinatesAbstract.hpp"

class RequerimentPieceCoordinatesTest : public RequerimentPieceCoordinatesAbstract
{
    public:
        RequerimentPieceCoordinatesTest(std::vector<std::pair<int, int> > nPLays, int numberPlays, std::string finalMessage);
        std::pair<int, int> getUserPieceCoordinates() override;
        void isResultExpected(std::string message) override;
    private:
        DataHandler dataHandler;
        int _counterGetUserPieceCoordinates = 0;
        std::vector<std::pair<int, int>> _plays;
        int _numberPlays;
        std::string _finalMessage;

};
#endif 
