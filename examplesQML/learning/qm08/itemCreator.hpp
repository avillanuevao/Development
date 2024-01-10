// itemCreator.hpp
#ifndef ITEMCREATOR_H
#define ITEMCREATOR_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QString>
#include <memory>
#include "buttonHandler.hpp"


class ItemCreator : public QObject {
    Q_OBJECT
public:
    explicit ItemCreator(QQmlApplicationEngine &engine, QObject *parent = nullptr);
    Q_INVOKABLE void createItem(QString property, int columnSpan, int rowSpan, bool fill);

private:
    QQmlApplicationEngine &engine;
    std::unique_ptr<ButtonHandler> buttonHandler;
};

#endif //
