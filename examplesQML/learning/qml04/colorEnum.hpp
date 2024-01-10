#pragma once

#include <QString>

class Color
{
public:
    enum Colors
    {
        blue,
        green,
        red
    };

    QString colorsToString(Colors colors);
};
