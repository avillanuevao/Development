#include "header/RequerimentBoardSizeTest.hpp"

RequerimentBoardSizeTest::RequerimentBoardSizeTest(std::shared_ptr<Board> board, std::vector<std::pair<int, int>> boardSizes, int numberInvalidBoardSizes) {
    _board = board;
    _boardSizes = boardSizes;
    _numberInvalidBoardSizes = numberInvalidBoardSizes;
}

std::pair<int, int> RequerimentBoardSizeTest::getUserBoardSize()
{
    do
    {
        _numberRows = _boardSizes[_counterGetUserBoardSize].first;
        _numberColumns = _boardSizes[_counterGetUserBoardSize].second;
        _counterGetUserBoardSize++;
    } while (!checkUserBoardSize(_numberRows) || !checkUserBoardSize(_numberColumns));
    return std::pair<int, int>(_numberRows, _numberColumns);
}

bool RequerimentBoardSizeTest::checkUserBoardSize(int value)
{
    if(value >= 3)
    {
        return true;
    }
    return false;
}

void RequerimentBoardSizeTest::isExpectedResult()
{
    if((_board->getBoardDimension().numberRows == _numberRows) && (_board->getBoardDimension().numberColumns == _numberColumns) && (_counterGetUserBoardSize  == _numberInvalidBoardSizes))
    {
        std::cout << "Test 'RequerimentBoardSizeTest' passed" << std::endl;
    }
    else
    {
        std::cout << "Test 'RequerimentBoardSizeTest' failed" << std::endl;
    }
}
