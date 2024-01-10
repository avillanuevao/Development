#include "SceneModel.hpp"

SceneModel::SceneModel()
{

}

void SceneModel::setColumnQQuickItem(QVector<QQuickItem*> quickItem)
{
    m_columnQQuickItem.append(quickItem);
}

void SceneModel::setRowQQuickItem(QVector<QQuickItem*> quickItem)
{
    m_rowQQuickItem.append(quickItem);
}

void SceneModel::setTextQQuickItem(QVector<QQuickItem*> quickItem)
{
    m_textQQuickItem.append(quickItem);
}

void SceneModel::setButtonQQuickItem(std::map<UIButtonType, QQuickItem *> quickItem)
{

    m_buttonQQuickItem = quickItem;
}

void SceneModel::setComboBoxQQuickItem(std::map<UIComboBoxType, QQuickItem *> quickItem)
{
    m_comboBoxQQuickItem = quickItem;
}

QVector<QQuickItem *> SceneModel::getColumnQQuickItem()
{
    return m_columnQQuickItem;
}

QVector<QQuickItem *> SceneModel::getRowQQuickItem()
{
    return m_rowQQuickItem;
}

QVector<QQuickItem *> SceneModel::getTextQQuickItem()
{
    return m_textQQuickItem;
}

std::map<UIButtonType, QQuickItem *> SceneModel::getButtonQQuickItem()
{
    return m_buttonQQuickItem;
}

std::map<UIComboBoxType, QQuickItem *> SceneModel::getComboBoxQQuickItem()
{
    return m_comboBoxQQuickItem;
}
