#ifndef SCENECREATOR_HPP
#define SCENECREATOR_HPP

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQuickWindow>
#include <QtQml>
#include <QString>
#include <QVector>

enum UIButtonType
{
    Accept,
    Reset
};

enum UIOperationType
{
    Fund,
    Expense
};

enum UIComboBoxType
{
    Language,
    Operation,
    BudgetAllocation
};

class SceneCreator : public QObject
{
    Q_OBJECT
signals:
    void buttonClicked();
public:
    explicit SceneCreator(QQmlApplicationEngine &engine, QObject *parent = nullptr);
    void createColumn(QVector<QQuickItem*>& containter);
    void createRow(QVector<QQuickItem*>& parent, QVector<QQuickItem*>& containter, int parentID);
    void createButton(QVector<QQuickItem*>& parent, std::map<UIButtonType, QQuickItem*>& container, UIButtonType idButton, int parentID);
    void createComboBox(QVector<QQuickItem*>& parent, std::map<UIComboBoxType, QQuickItem*>& container, UIComboBoxType idComboBox, int parentID);
    void createTextField(QVector<QQuickItem*>& parent, int parentID);
    void createTextElement(QVector<QQuickItem*>& parent, QVector<QQuickItem*>& containter, int parentID);
private slots:
    QQuickItem *handler();
private:
    QQmlApplicationEngine &m_engine;
};

#endif // SCENECREATOR_HPP
