#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QVector>
#include "colorEnum.hpp"

class scene : public QObject {
    Q_OBJECT

public:
    explicit scene(QQmlApplicationEngine& engine, QObject *parent = nullptr);

public slots:
    void create_rect_object(const QVector<int>& parameters, const Color::Colors color);

private:
    QQmlApplicationEngine& engine;
};

#endif // SCENE_H
