#ifndef RECTANGLECREATOR_H
#define RECTANGLECREATOR_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>

class RectangleCreator : public QObject
{
    Q_OBJECT

public:
    explicit RectangleCreator(QQmlApplicationEngine& engine, QObject *parent = nullptr);
public slots:
    void createRectangle(const char* property);
private:
    QQmlApplicationEngine& engine;
};

#endif
