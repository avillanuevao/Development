#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <memory>
#include "PlayerCharacter.hpp"
#include "Player.hpp"

class Game
{
    public:
        Game();
        void addAvailableCharacter(PlayerCharacter::playerCharacter availablePlayer);
        void addPlayer();
        void initPlayers();
        void setMaxNumberGames(int maxGames);
        void increaseGameNumber();
        void setMaxNumberOfPlayers(int maxPlayers);
        void setNumberOfPlayers(int numbPlayers);
        void setTypeGame(int typeGame);
        const int getMaxNumberGames();
        const int getGameNumber();
        const int getMaxNumberOfPlayers();
        const int getNumberOfPlayers();
        const int getMinNumberOfPlayers();
        const int getAvailableCharacterSize();
        const int getTypeGame();
        PlayerCharacter::playerCharacter switchPlayer();
    private:
        std::shared_ptr<Player> player;
        std::vector<Player> existingPlayer;
        std::vector<PlayerCharacter::playerCharacter> availableCharacter;
        const int MINNUMBERPLAYERS = 2;
        int maxNumberPlayers;
        int numberPlayers;
        int gameNumber = 0;
        int maxNumberOfGames;
        int _typeGame;
};
#endif 
