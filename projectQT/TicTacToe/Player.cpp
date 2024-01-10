#include "header/Player.hpp"
Player::Player(){}

void Player::setPlayerSelected(PlayerCharacter::playerCharacter selectedPlayer)
{
    playerSelected = selectedPlayer;
}

PlayerCharacter::playerCharacter Player::getPlayerSelected()
{
    return playerSelected;
}