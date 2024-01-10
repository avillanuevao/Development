#include <memory>
#include "header/Game.hpp"
#include "header/GameTypeInitializer.hpp"
#include "header/GameBoardInitializer.hpp"
#include "header/QuantityOfPlayersController.hpp"
#include "header/ManageGame.hpp"

#include "header/RequerimentTypeGameAbstract.hpp"
#include "header/RequerimentTypeGameUser.hpp"

#include "header/RequerimentLanguageAbstract.hpp"
#include "header/RequerimentLanguageTest.hpp"
#include "header/RequerimentLanguageUser.hpp"

#include "header/RequerimentBoardSizeAbstract.hpp"
#include "header/RequerimentBoardSizeTest.hpp"
#include "header/RequerimentBoardSizeUser.hpp"

#include "header/RequerimentQuantityOfPlayersAbstract.hpp"
#include "header/RequerimentQuantityOfPlayersTest.hpp"
#include "header/RequerimentQuantityOfPlayersUser.hpp"

#include "header/RequerimentPieceCoordinatesAbstract.hpp"
#include "header/RequerimentPieceCoordinatesTest.hpp"
#include "header/RequerimentPieceCoordinatesUser.hpp"
#include "header/RequerimentPieceCoordinatesIA.hpp"

#include "header/PrintMatchResultAbstract.hpp"
#include "header/PrintMatchResultTest.hpp"
#include "header/PrintMatchResultUser.hpp"

#include "header/PrintErrorMessageAbstract.hpp"
#include "header/PrintErrorMessageTest.hpp"
#include "header/PrintErrorMessageUser.hpp"

#include "header/PrintBoardGameAbstract.hpp"
#include "header/PrintBoardGameTest.hpp"
#include "header/PrintBoardGameUser.hpp"



void userPlaying()
{
    std::shared_ptr<Board> board(new Board());
    std::shared_ptr<Game> game(new Game());
    std::shared_ptr<RequerimentTypeGameAbstract> requerimentTypeGame(new RequerimentTypeGameUser(game));
    std::shared_ptr<RequerimentLanguageAbstract> requerimentLanguage(new RequerimentLanguageUser());
    std::shared_ptr<RequerimentBoardSizeAbstract> requerimentBoardSizeTest(new RequerimentBoardSizeUser());
    std::shared_ptr<RequerimentQuantityOfPlayersAbstract> requerimentQuantityOfPlayers(new RequerimentQuantityOfPlayersUser());
    std::shared_ptr<RequerimentPieceCoordinatesAbstract> requerimentPieceCoordinates(new RequerimentPieceCoordinatesUser());
    std::shared_ptr<RequerimentPieceCoordinatesAbstract> requerimentPieceCoordinatesIA(new RequerimentPieceCoordinatesIA(board));

    std::shared_ptr<PrintBoardGameAbstract> printBoardGame(new PrintBoardGameUser(board));
    std::shared_ptr<PrintMatchResultAbstract> printMatchResult(new PrintMatchResultUser());
    std::shared_ptr<PrintErrorMessageAbstract> printErrorMessage(new PrintErrorMessageUser());

    GameTypeInitializer gameTypeInitializer(game, requerimentTypeGame);
    GameBoardInitializer gameBoardInitializer(game, board, printBoardGame, requerimentBoardSizeTest);
    QuantityOfPlayersController quantityOfPlayersController(board, game, requerimentQuantityOfPlayers);
    ManageGame piecePlacementController(board, game, printBoardGame, requerimentPieceCoordinates, requerimentPieceCoordinatesIA,printMatchResult, printErrorMessage);

    requerimentLanguage->getUserLanguage();
    requerimentLanguage->isExpectedResult();
    gameBoardInitializer.gameBoardInitializerExecute();
    quantityOfPlayersController.quantityOfPlayersControllerExecute();
    gameTypeInitializer.gameTypeInitializerExecute();
    piecePlacementController.piecePlacementControllerExecute();
}


int main()
{
    /*
    TestParameters testParameters;
    testParameters.languages = {3, 0};
    testParameters.boardSizes = {{0,0},{3,0},{0,3},{3,3}};
    testParameters.numberOfPlayers = {-1, 3, 2};
    testParameters.plays = {{0,0},{1,0},{0,1},{1,1},{0,2}};

    testParameters.boardSizesUsed = 4;
    testParameters.numberPlayersUsed = 3;
    testParameters.playsUsed = 5;
    testParameters.finalMessage = "Partida finalizada. Enhorabuena: x";
    test(testParameters);
    */
    userPlaying();
}

struct TestParameters
{
    std::vector<int> languages;
    std::vector<std::pair<int, int>> boardSizes;
    std::vector<int> numberOfPlayers;
    std::vector<std::pair<int, int>> plays;
    int boardSizesUsed;
    int numberPlayersUsed;
    int playsUsed;
    std::string finalMessage;
};

/*
void test(const TestParameters& testParameters)
{
    std::shared_ptr<Board> board(new Board());
    std::shared_ptr<Game> game(new Game());

    std::shared_ptr<RequerimentLanguageAbstract> requerimentLanguage(new RequerimentLanguageTest(testParameters.languages));
    std::shared_ptr<RequerimentBoardSizeAbstract> requerimentBoardSizeTest(new RequerimentBoardSizeTest(board, testParameters.boardSizes, testParameters.boardSizesUsed));
    std::shared_ptr<RequerimentQuantityOfPlayersAbstract> requerimentQuantityOfPlayers(new RequerimentQuantityOfPlayersTest(game, testParameters.numberOfPlayers, testParameters.numberPlayersUsed));
    std::shared_ptr<RequerimentPieceCoordinatesAbstract> requerimentPieceCoordinates(new RequerimentPieceCoordinatesTest(testParameters.plays, testParameters.playsUsed, testParameters.finalMessage));

    std::shared_ptr<PrintBoardGameAbstract> printBoardGame(new PrintBoardGameTest());
    std::shared_ptr<PrintMatchResultAbstract> printMatchResult(new PrintMatchResultTest());
    std::shared_ptr<PrintErrorMessageAbstract> printErrorMessage(new PrintErrorMessageTest());

    GameBoardInitializer gameBoardInitializer(board, printBoardGame, requerimentBoardSizeTest);
    QuantityOfPlayersController quantityOfPlayersController(board, game, requerimentQuantityOfPlayers);
    ManageGame piecePlacementController(board, game, printBoardGame, requerimentPieceCoordinates, printMatchResult, printErrorMessage);

    requerimentLanguage->getUserLanguage();
    requerimentLanguage->isExpectedResult();

    gameBoardInitializer.gameBoardInitializerExecute();
    quantityOfPlayersController.quantityOfPlayersControllerExecute();
    piecePlacementController.piecePlacementControllerExecute();
}
*/
