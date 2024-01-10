#ifndef QMLLOADER_H
#define QMLLOADER_H

#include <QObject>
#include <QQmlApplicationEngine>

class QMLLoader : public QObject
{
    Q_OBJECT

public:
    explicit QMLLoader(QObject *parent = nullptr);

    Q_INVOKABLE void loadNewQML(const QString &qmlFile);

private:
    QQmlApplicationEngine m_engine;
};

#endif // QMLLOADER_H
