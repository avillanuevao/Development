#ifndef REQUERIMENTQUANTITYOFPLAYERSUSER_H
#define REQUERIMENTQUANTITYOFPLAYERSUSER_H

#include "RequerimentQuantityOfPlayersAbstract.hpp"

class RequerimentQuantityOfPlayersUser : public RequerimentQuantityOfPlayersAbstract
{
    public:
        RequerimentQuantityOfPlayersUser();
        int getUserQuantityOfPlayers() override;
        bool checkUserQuantityOfPlayers(int value) override;
        void isResultExpected() override;
    private:
        DataHandler dataHandler;
};
#endif 
