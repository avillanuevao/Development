#ifndef REQUERIMENTOPTIONDISPLAY_HPP
#define REQUERIMENTOPTIONDISPLAY_HPP

#include <iostream>
#include <QTextStream>
#include <QString>
#include <QDebug>

class RequerimentOptionDisplay
{
public:
    RequerimentOptionDisplay();
    void setOption();
    int getOption();
private:
    int m_option;
};

#endif // REQUERIMENTOPTIONDISPLAY_HPP
