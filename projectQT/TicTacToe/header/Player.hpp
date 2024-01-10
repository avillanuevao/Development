#ifndef PLAYER_H
#define PLAYER_H

#include "PlayerCharacter.hpp"

class Player
{
    public:
        Player();
        void setPlayerSelected(PlayerCharacter::playerCharacter selectedPlayer);
        PlayerCharacter::playerCharacter getPlayerSelected();
    private:
        PlayerCharacter::playerCharacter playerSelected;
};
#endif 