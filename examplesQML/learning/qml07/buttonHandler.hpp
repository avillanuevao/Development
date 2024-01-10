// ButtonHandler.h
#pragma once

#include <QObject>
#include <QDebug>
#include <QString>
class ButtonHandler : public QObject {
    Q_OBJECT
signals:
    void buttonClicked(QString buttonLabel); // Puedes incluir parámetros adicionales según tus necesidades
public slots:
    void handleButtonClick();
    void handleButtonClickTry();

};
