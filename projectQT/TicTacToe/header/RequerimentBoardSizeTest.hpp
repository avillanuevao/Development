#ifndef REQUERIMENTBOARDSIZETEST_H
#define REQUERIMENTBOARDSIZETEST_H

#include "RequerimentBoardSizeAbstract.hpp"

class RequerimentBoardSizeTest : public RequerimentBoardSizeAbstract
{
    public:
        RequerimentBoardSizeTest(std::shared_ptr<Board> board, std::vector<std::pair<int, int>> boardSizes, int numberInvalidBoardSizes);
        std::pair<int, int> getUserBoardSize() override;
        bool checkUserBoardSize(int value) override;
        void isExpectedResult() override;
    private:
        DataHandler dataHandler;
        std::shared_ptr<Board> _board;
        std::vector<std::pair<int, int>> _boardSizes;
        int _numberRows;
        int _numberColumns;
        int _numberInvalidBoardSizes;
        int _counterGetUserBoardSize = 0;
};
#endif 
