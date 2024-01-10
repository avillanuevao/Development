#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QVector>
#include "scene.hpp"
#include "colorEnum.hpp"

int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    scene sc(engine);

    QQmlContext* context = engine.rootContext();
    context->setContextProperty("sc", &sc);

    if (engine.rootObjects().isEmpty())
        return -1;

    QVector<int> rectangleAParameters = {60, 40, 200, 100, 0};
    Color::Colors rectangleAColor = Color::Colors::blue;
    QVector<int> rectangleBParameters = {60, 40, 100, 200, 0};
    Color::Colors rectangleBColor = Color::Colors::green;

    sc.create_rect_object(rectangleAParameters, rectangleAColor);
    sc.create_rect_object(rectangleBParameters, rectangleBColor);
    return app.exec();
}
