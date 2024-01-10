#include "header/PlayerCharacter.hpp"

PlayerCharacter::PlayerCharacter(){}

std::string PlayerCharacter::enumToString(playerCharacter playerChar)
{
    std::string stringPlayerCharacter;
    switch (playerChar)
    {
    case 0:
        stringPlayerCharacter = "x";
        break;
    case 1:
        stringPlayerCharacter = "o";
        break;
    case 2:
        stringPlayerCharacter = "l";
        break;
    case 3:
        stringPlayerCharacter = "u";
        break;
    case 4:
        stringPlayerCharacter = " ";
        break;
    default:
        stringPlayerCharacter = " ";
        break;
    }
    return stringPlayerCharacter;
}
