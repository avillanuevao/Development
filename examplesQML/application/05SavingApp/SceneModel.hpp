#ifndef SCENEMODEL_HPP
#define SCENEMODEL_HPP

#include "SceneCreator.hpp"
#include <utility>

class SceneModel
{
public:
    SceneModel();
    void setColumnQQuickItem(QVector<QQuickItem*> quickItem);
    void setRowQQuickItem(QVector<QQuickItem*> quickItem);
    void setTextQQuickItem(QVector<QQuickItem*> quickItem);
    void setButtonQQuickItem(std::map<UIButtonType, QQuickItem*> quickItem);
    void setComboBoxQQuickItem(std::map<UIComboBoxType, QQuickItem*> quickItem);
    QVector<QQuickItem*> getColumnQQuickItem();
    QVector<QQuickItem*> getRowQQuickItem();
    QVector<QQuickItem*> getTextQQuickItem();
    std::map<UIButtonType, QQuickItem*> getButtonQQuickItem();
    std::map<UIComboBoxType, QQuickItem*> getComboBoxQQuickItem();
private:
    QVector<QQuickItem*> m_columnQQuickItem;
    QVector<QQuickItem*> m_rowQQuickItem;
    QVector<QQuickItem*> m_textQQuickItem;
    std::map<UIButtonType, QQuickItem*> m_buttonQQuickItem;
    std::map<UIComboBoxType, QQuickItem*> m_comboBoxQQuickItem;
};

#endif // SCENEMODEL_HPP
