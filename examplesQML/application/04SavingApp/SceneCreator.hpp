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
#include "AppController.hpp"
#include "Language.hpp"

enum UIButtonType
{
    Accept,
    Reset
};
//Option
enum UITransactionType
{
    Fund,
    Expense
};
//
enum UIItemType
{
    Transaction,
    Bucket,
    Language
};

class SceneCreator : public QObject
{
    Q_OBJECT
public:
    explicit SceneCreator(QQmlApplicationEngine &engine, QObject *parent = nullptr);
    void createScene();
public slots:
    void handleButtonClicked();
    void handleCurrentIndexChanged();
    void handleNumericTextChanged();
private:
    WordBook m_WordBook;
    AppController m_AppController;
    QQmlApplicationEngine &m_engine;
    QVector<QQuickItem*> m_itemIDColumn;
    QVector<QQuickItem*> m_itemIDRow;
    std::map<UIButtonType, QQuickItem*> m_buttonIdContainter;
    std::map<UIItemType, QQuickItem*> m_comboBoxIdContainter;
    QVector<QQuickItem*> m_textElement;
    int m_selectedLanguage = 0;
    int m_selectedType = 0;
    int m_selectedBucket = 0;
    int m_amountMoney = 0;
    void createColumn();
    void createRow(QVector<QQuickItem*> parent, int parentID);
    void createButton(UIButtonType idButton, QVector<QQuickItem*> parent, int parentID);
    void createComboBox(UIItemType idComboBox, QVector<QQuickItem*> parent, int parentID);
    void createTextField(QVector<QQuickItem*> parent, int parentID);
    void createTextElement(QVector<QQuickItem*> parent, int parentID);
    void modifyTextElement(int newText);
    void initializeTextLanguage();
    void setTextLanguage();
};

#endif // SCENECREATOR_HPP
