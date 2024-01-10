#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "rectangleCreator.hpp"
#include "textContainerCreator.hpp"

int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    RectangleCreator rectangleC(engine);
    TextContainerCreator textContainerC(engine);

    QQmlContext* context = engine.rootContext();
    context->setContextProperty("rectangleC", &rectangleC);
    context->setContextProperty("textContainerC", &textContainerC);

    if (engine.rootObjects().isEmpty())
        return -1;

    rectangleC.createRectangle("rowLayoutA");
    rectangleC.createRectangle("rowLayoutA");
    rectangleC.createRectangle("rowLayoutA");
    rectangleC.createRectangle("rowLayoutA");

    rectangleC.createRectangle("rowLayoutB");
    rectangleC.createRectangle("rowLayoutB");
    rectangleC.createRectangle("rowLayoutB");
    rectangleC.createRectangle("rowLayoutB");

    rectangleC.createRectangle("rowLayoutC");
    rectangleC.createRectangle("rowLayoutC");
    rectangleC.createRectangle("rowLayoutC");
    rectangleC.createRectangle("rowLayoutC");

    rectangleC.createRectangle("rowLayoutD");
    rectangleC.createRectangle("rowLayoutD");
    rectangleC.createRectangle("rowLayoutD");
    rectangleC.createRectangle("rowLayoutD");

    return app.exec();
}

