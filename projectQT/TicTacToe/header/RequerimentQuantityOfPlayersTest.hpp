#ifndef REQUERIMENTQUANTITYOFPLAYERSTEST_H
#define REQUERIMENTQUANTITYOFPLAYERSTEST_H

#include "RequerimentQuantityOfPlayersAbstract.hpp"

class RequerimentQuantityOfPlayersTest : public RequerimentQuantityOfPlayersAbstract
{
    public:
        RequerimentQuantityOfPlayersTest(std::shared_ptr<Game> game, std::vector<int> nPlayers, int numberInvalidNumberPlayers);
        int getUserQuantityOfPlayers() override;
        bool checkUserQuantityOfPlayers(int value) override;
        void isResultExpected() override;
    private:
        DataHandler dataHandler;
        std::vector<int> _nPlayers;
        std::shared_ptr<Game> _game;
        int _numberPlayers;
        int _numberInvalidNumberPlayers;
        int _counterGetUserQuantityOfPlayers = 0;
};
#endif 
