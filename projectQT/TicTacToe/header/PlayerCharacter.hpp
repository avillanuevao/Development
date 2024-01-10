#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include <string>

class PlayerCharacter
{
    public:
        enum playerCharacter
        {
            x,
            o,
            l,
            u,
            none
        };
        PlayerCharacter();
        std::string enumToString(playerCharacter playerChar);
};


#endif 