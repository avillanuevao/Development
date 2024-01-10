#ifndef TEXTCONTAINERCREATOR_H
#define TEXTCONTAINERCREATOR_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQmlProperty>

class TextContainerCreator : public QObject
{
    Q_OBJECT

public:
    explicit TextContainerCreator(QQmlApplicationEngine& engine, QObject *parent = nullptr);
public slots:
    void createTextContainer(const char* property);
private:
    QQmlApplicationEngine& engine;
};

#endif
