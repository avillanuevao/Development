#ifndef MANAGEGAME_H
#define MANAGEGAME_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <memory>
#include "Board.hpp"
#include "Game.hpp"
#include "PlayerCharacter.hpp"
#include "PrintBoardGameAbstract.hpp"
#include "PrintMatchResultAbstract.hpp"
#include "PrintErrorMessageAbstract.hpp"
#include "RequerimentPieceCoordinatesAbstract.hpp"
#include "Language.hpp"

class ManageGame
{
    public:
        ManageGame(std::shared_ptr<Board> board, std::shared_ptr<Game> game, std::shared_ptr<PrintBoardGameAbstract> printBoardGame, std::shared_ptr<RequerimentPieceCoordinatesAbstract> requerimentPieceCoordinates,std::shared_ptr<RequerimentPieceCoordinatesAbstract> requerimentPieceCoordinatesIA, std::shared_ptr<PrintMatchResultAbstract> printMatchResult, std::shared_ptr<PrintErrorMessageAbstract> printErrorMessage);
        void piecePlacementControllerExecute();
    private:
        std::shared_ptr<Board> _board;
        std::shared_ptr<Game> _game;
        std::shared_ptr<PlayerCharacter> _playerCharacter;
        std::shared_ptr<PrintBoardGameAbstract> _printBoardGame;
        std::shared_ptr<PrintMatchResultAbstract> _printMatchResult;
        std::shared_ptr<PrintErrorMessageAbstract> _printErrorMessage;
        std::vector<std::shared_ptr<RequerimentPieceCoordinatesAbstract>> _requerimentPieceCoordinates;
        //std::shared_ptr<RequerimentPieceCoordinatesAbstract> _requerimentPieceCoordinates;
        //std::shared_ptr<RequerimentPieceCoordinatesAbstract> _requerimentPieceCoordinatesIA;
        Language* languageInstance;
        
        std::pair<int, int> getPieceCoordinatesFormView(int actualPlayer);
        std::pair<int, int> getPieceCoordinates(int actualPlayer);
        void placePieceOnBoard(std::pair<int, int> userPieceCoordinates, PlayerCharacter::playerCharacter player);
        void increaseGameNumber();
        void printBoardGame();
        void gameOverMessage(PlayerCharacter::playerCharacter actualPlayer);
        int getMaxNumberGames();
        void setMaxNumberGames();
        bool checkGameStatus();
};
#endif 
