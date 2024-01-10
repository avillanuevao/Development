#include "colorEnum.hpp"

QString Color::colorsToString(Colors colors)
{
    switch (colors) {
        case blue:
            return "blue";
            break;
        case green:
                return "green";
                break;
        case red:
                return "red";
                break;
    }
}
