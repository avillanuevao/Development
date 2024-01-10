// sceneCreator.hpp
#ifndef SCENECREATOR_H
#define SCENECREATOR_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QString>
#include <QTimer>
#include <QVector>
#include <memory>
#include "buttonCreator.hpp"
#include "comboBoxCreator.hpp"
#include "rectangleCreator.hpp"

class SceneCreator : public QObject {
    Q_OBJECT
public:
    explicit SceneCreator(QQmlApplicationEngine &engine, QObject *parent = nullptr);
    Q_INVOKABLE void createSceneMoneyBackground();
    Q_INVOKABLE void createSceneExpenses();


private:
    QQmlApplicationEngine &engine;
    ButtonCreator buttonCreator;
    ComboBoxCreator comboBoxCreator;
    RectangleCreator rectangleCreator;

    void createScene(QString property, int height, int width, QVector<QString> textButton, QVector<QString> comboContainer);
    void removePreviousScene(QString property, QString objectNameNotRemoveA, QString objectNameNotRemoveB);

};

#endif // SCENECREATOR_H
