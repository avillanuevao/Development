// buttonCreator.hpp
#ifndef COMBOBOXCREATOR_H
#define COMBOBOXCREATOR_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QString>
#include <QTimer>
#include <memory>
#include <QStringListModel>

class ComboBoxCreator : public QObject {
    Q_OBJECT
public:
    explicit ComboBoxCreator(QQmlApplicationEngine &engine, QObject *parent = nullptr);
    Q_INVOKABLE void createComboBox(QString property, int height, int width, QVector<QString> comboContainer);

private:
    QQmlApplicationEngine &engine;
};

#endif // BUTTONCREATOR_H
