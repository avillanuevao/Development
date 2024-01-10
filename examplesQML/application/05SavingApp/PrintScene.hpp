#ifndef PRINTSCENE_HPP
#define PRINTSCENE_HPP

#include <QObject>
#include "SceneCreator.hpp"
#include "Language.hpp"

class PrintScene: public QObject
{
    Q_OBJECT
public:
    PrintScene(QQmlApplicationEngine &engine, QObject *parent = nullptr);
    void paintInterface();
    void updateInterface();
    QVector<QQuickItem*> getColumnQQuickItem();
    QVector<QQuickItem*> getRowQQuickItem();
    QVector<QQuickItem*> getTextQQuickItem();
    QVector<QQuickItem*> getTextFieldQQuickItem();
    std::map<UIButtonType, QQuickItem*> getButtonQQuickItem();
    std::map<UIComboBoxType, QQuickItem*> getComboBoxQQuickItem();
private:
    QQmlApplicationEngine &m_engine;
    SceneCreator m_sceneCreator;
    WordBook m_wordBook;
    QVector<QQuickItem*> m_columnQQuickItem;
    QVector<QQuickItem*> m_rowQQuickItem;
    QVector<QQuickItem*> m_textQQuickItem;
    QVector<QQuickItem*> m_textFieldQQuickItem;
    std::map<UIButtonType, QQuickItem*> m_buttonQQuickItem;
    std::map<UIComboBoxType, QQuickItem*> m_comboBoxQQuickItem;

    void paintControls();
    void paintTextInterface();
};

#endif // PRINTSCENE_HPP
