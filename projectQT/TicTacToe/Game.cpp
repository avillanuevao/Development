#include "header/Game.hpp"
Game::Game()
{
    addAvailableCharacter(PlayerCharacter::playerCharacter::x);
    addAvailableCharacter(PlayerCharacter::playerCharacter::o);
    addAvailableCharacter(PlayerCharacter::playerCharacter::l);
    addAvailableCharacter(PlayerCharacter::playerCharacter::u);
}

void Game::addPlayer()
{
    Player player;
    if(!availableCharacter.empty())
    {
        player.setPlayerSelected(availableCharacter[0]);
        existingPlayer.push_back(player);
        availableCharacter.erase(availableCharacter.begin());
    }
}

void Game::setMaxNumberGames(int maxGames)
{
    maxNumberOfGames = maxGames;
}

const int Game::getMaxNumberGames()
{
    return maxNumberOfGames;
}

void Game::addAvailableCharacter(PlayerCharacter::playerCharacter availablePlayer)
{
    availableCharacter.push_back(availablePlayer);
}

PlayerCharacter::playerCharacter Game::switchPlayer()
{
    int maxNumberPlayers = existingPlayer.size();
    int playerOn = 0;
    playerOn = gameNumber % maxNumberPlayers;
    return existingPlayer[playerOn].getPlayerSelected();
}

void Game::increaseGameNumber()
{
    gameNumber++;
}

const int Game::getGameNumber()
{
    return gameNumber;
}

void Game::setMaxNumberOfPlayers(int maxPlayers)
{
    maxNumberPlayers = maxPlayers;
}

void Game::setNumberOfPlayers(int numbPlayers)
{
    numberPlayers = numbPlayers;
}

void Game::setTypeGame(int typeGame)
{
    _typeGame = typeGame;
}


const int Game::getMaxNumberOfPlayers()
{
    return maxNumberPlayers;
}

const int Game::getMinNumberOfPlayers()
{
    return MINNUMBERPLAYERS;
}

const int Game::getNumberOfPlayers()
{   
    return numberPlayers;
}

const int Game::getAvailableCharacterSize()
{
    return availableCharacter.size();
}

void Game::initPlayers()
{
    int counter = numberPlayers;
    while(counter > 0)
    {
        addPlayer();
        counter--;
    }
}

const int Game::getTypeGame()
{
    return _typeGame;
}
