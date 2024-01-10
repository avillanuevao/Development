// buttonCreator.hpp
#ifndef BUTTONCREATOR_H
#define BUTTONCREATOR_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QString>
#include <QTimer>
#include <memory>

class ButtonCreator : public QObject {
    Q_OBJECT
public:
    explicit ButtonCreator(QQmlApplicationEngine &engine, QObject *parent = nullptr);
    Q_INVOKABLE void createButton(QString property, int height, int width, QString textButton);

private:
    QQmlApplicationEngine &engine;
};

#endif // BUTTONCREATOR_H
