#ifndef QUANTITYOFPLAYERSCONTROLLER_H
#define QUANTITYOFPLAYERSCONTROLLER_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <memory>
#include "Board.hpp"
#include "Game.hpp"
#include "RequerimentQuantityOfPlayersAbstract.hpp"

class QuantityOfPlayersController
{
    public:
        QuantityOfPlayersController(std::shared_ptr<Board> board, std::shared_ptr<Game> game, std::shared_ptr<RequerimentQuantityOfPlayersAbstract> requerimentQuantityOfPlayers);
        void quantityOfPlayersControllerExecute();
    private:
        std::shared_ptr<Board> _board;
        std::shared_ptr<Game> _game;
        std::shared_ptr<RequerimentQuantityOfPlayersAbstract> _requerimentQuantityOfPlayers;

        int calculateMaxNumberPlayers();
        void setMaxNumberPlayersInModel();
        void setNumberPlayersInModel();
        void addPlayers();
};
#endif 
