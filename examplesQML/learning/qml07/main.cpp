#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "buttonCreator.hpp"
#include "rectangleCreator.hpp"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    ButtonCreator buttonCreator(engine);
    engine.rootContext()->setContextProperty("buttonCreator", &buttonCreator);

    RectangleCreator rectangleCreator(engine);
    engine.rootContext()->setContextProperty("rectangleCreator", &rectangleCreator);


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
