#include "SceneController.hpp"

SceneController::SceneController(QQmlApplicationEngine &engine, QObject *parent) :
    QObject(parent),
    m_engine(engine),
    m_sceneCreator(engine),
    m_printScene(engine)
{
    // Constructor implementation
    //QObject::connect(&m_sceneCreator, SIGNAL(buttonClicked()), this, SLOT(prueba()));
    m_printScene.paintInterface();

    m_sceneModel.setColumnQQuickItem(m_printScene.getColumnQQuickItem());
    m_sceneModel.setRowQQuickItem(m_printScene.getRowQQuickItem());
    m_sceneModel.setTextQQuickItem(m_printScene.getTextQQuickItem());
    m_sceneModel.setButtonQQuickItem(m_printScene.getButtonQQuickItem());
    m_sceneModel.setComboBoxQQuickItem(m_printScene.getComboBoxQQuickItem());
}

void SceneController::setInteractionHandler()
{
    std::map<UIButtonType, QQuickItem*> buttonQQuickItem = m_sceneModel.getButtonQQuickItem();
    if (buttonQQuickItem.empty()) {
        qDebug() << "Button Map is empty!";
    }
    for (const auto& pair : buttonQQuickItem) {
        UIButtonType idButton = pair.first;
        QQuickItem* item = pair.second;
        connect(item, SIGNAL(clicked()), this, SLOT(setButtonHandler()));
    }
    std::map<UIComboBoxType, QQuickItem*> comboBoxQQuickItem = m_sceneModel.getComboBoxQQuickItem();
    for (const auto& pair : comboBoxQQuickItem) {
        UIComboBoxType idButton = pair.first;
        QQuickItem* item = pair.second;
        connect(item, SIGNAL(currentIndexChanged()), this, SLOT(setComboBoxHandler()));
    }

    QVector<QQuickItem*> textQQuickItem = m_sceneModel.getTextQQuickItem();
    for (QQuickItem* item : textQQuickItem) {
        //textField no es almacenado -> Hacerlo para recibir cambios
        //connect(item, SIGNAL(textChanged()), this, SLOT(setTextHandler()));
    }
}

void SceneController::setButtonHandler()
{
    qDebug() << "setButtonHandler";
}

void SceneController::setComboBoxHandler()
{
    qDebug() << "setComboBoxHandler";
}

void SceneController::setTextHandler()
{
    qDebug() << "setTextHandler";
}
