// rectangleCreator.hpp
#ifndef RECTANGLECREATOR_H
#define RECTANGLECREATOR_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QString>
#include <QTimer>
#include <memory>

class RectangleCreator : public QObject {
    Q_OBJECT
public:
    explicit RectangleCreator(QQmlApplicationEngine &engine, QObject *parent = nullptr);
    Q_INVOKABLE void createRectangle(QString property, int height, int width);

private:
    QQmlApplicationEngine &engine;
};

#endif // BUTTONCREATOR_H
