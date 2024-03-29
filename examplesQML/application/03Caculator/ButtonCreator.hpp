#ifndef BUTTONCREATOR_H
#define BUTTONCREATOR_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QString>
#include <QQuickWindow>

class ButtonCreator : public QObject {
    Q_OBJECT
public:
    explicit ButtonCreator(QQmlApplicationEngine &engine, QObject *parent = nullptr);
    Q_INVOKABLE void createButton(QQuickItem* property, QString textButton, const std::function<void()> &connectFunction);
public slots:
    void handleButtonClick();
signals:
    void buttonClicked();
private:
    QQmlApplicationEngine &engine;
};

#endif
