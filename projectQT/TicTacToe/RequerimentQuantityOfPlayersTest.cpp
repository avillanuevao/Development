#include "header/RequerimentQuantityOfPlayersTest.hpp"

RequerimentQuantityOfPlayersTest::RequerimentQuantityOfPlayersTest(std::shared_ptr<Game> game, std::vector<int> nPlayers, int numberInvalidNumberPlayers)
{
    _game = game;
    _nPlayers = nPlayers;
    _numberInvalidNumberPlayers = numberInvalidNumberPlayers;
}

int RequerimentQuantityOfPlayersTest::getUserQuantityOfPlayers()
{
    do
    {
        _numberPlayers = _nPlayers[_counterGetUserQuantityOfPlayers];
        _counterGetUserQuantityOfPlayers++;
    } while (!checkUserQuantityOfPlayers(_numberPlayers));
    return _numberPlayers;
}

bool RequerimentQuantityOfPlayersTest::checkUserQuantityOfPlayers(int value)
{
    if(value >= 2)
    {
        return true;
    }
    return false;
}

void RequerimentQuantityOfPlayersTest::isResultExpected()
{
    if(_game->getNumberOfPlayers() == _numberPlayers && (_counterGetUserQuantityOfPlayers == _numberInvalidNumberPlayers))
    {
        std::cout << "Test 'RequerimentQuantityOfPlayersTest' passed"<< std::endl;
    }else
    {
        std::cout << "Test 'RequerimentQuantityOfPlayersTest' failed"<< std::endl;
    }
}
