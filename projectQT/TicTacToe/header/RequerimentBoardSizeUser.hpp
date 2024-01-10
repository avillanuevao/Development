#ifndef REQUERIMENTBOARDSIZEUSER_H
#define REQUERIMENTBOARDSIZEUSER_H

#include "RequerimentBoardSizeAbstract.hpp"

class RequerimentBoardSizeUser : public RequerimentBoardSizeAbstract
{
    public:
        RequerimentBoardSizeUser();
        std::pair<int, int> getUserBoardSize() override;
        bool checkUserBoardSize(int value) override;
        void isExpectedResult() override;
    private:
        DataHandler dataHandler;
};
#endif 
