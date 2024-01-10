#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "buttonCreator.hpp"
#include "sceneCreator.hpp"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    ButtonCreator buttonCreator(engine);
    engine.rootContext()->setContextProperty("buttonCreator", &buttonCreator);

    SceneCreator sceneCreator(engine);
    engine.rootContext()->setContextProperty("sceneCreator", &sceneCreator);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
