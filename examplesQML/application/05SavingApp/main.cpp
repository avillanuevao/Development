#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "SceneCreator.hpp"
#include "SceneController.hpp"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    auto sceneController = std::make_shared<SceneController>(engine);
    sceneController->setInteractionHandler();
    return app.exec();
}
