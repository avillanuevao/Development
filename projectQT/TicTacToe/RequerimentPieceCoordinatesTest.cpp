#include "header/RequerimentPieceCoordinatesTest.hpp"

RequerimentPieceCoordinatesTest::RequerimentPieceCoordinatesTest(std::vector<std::pair<int, int> > pLays, int numberPlays, std::string finalMessage)
{
    _plays = pLays;
    _numberPlays = numberPlays;
    _finalMessage = finalMessage;
}

std::pair<int, int> RequerimentPieceCoordinatesTest::getUserPieceCoordinates()
{
    std::pair<int, int> combination;

    combination = _plays[_counterGetUserPieceCoordinates];
    _counterGetUserPieceCoordinates++;
    return combination;
}

void RequerimentPieceCoordinatesTest::isResultExpected(std::string message)
{
    if((_counterGetUserPieceCoordinates == _numberPlays) && (_finalMessage == message))
    {
        std::cout << "Test 'RequerimentPieceCoordinatesTest' passed"<< std::endl;
    }else
    {
        std::cout << "Test 'RequerimentPieceCoordinatesTest' failed"<< std::endl;

    }
}
