#ifndef SCENECONTROLLER_HPP
#define SCENECONTROLLER_HPP

#include "SceneCreator.hpp"
#include "SceneModel.hpp"
#include "PrintScene.hpp"
#include "Language.hpp"

class SceneController : public QObject
{
    Q_OBJECT
public:
    SceneController(QQmlApplicationEngine &engine, QObject *parent = nullptr);
    void setInteractionHandler();
public slots:
    void setButtonHandler();
    void setComboBoxHandler();
    void setTextHandler();
private:
    QQmlApplicationEngine &m_engine;
    SceneModel m_sceneModel;
    SceneCreator m_sceneCreator;
    PrintScene m_printScene;
};

#endif // SCENECONTROLLER_HPP
