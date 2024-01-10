#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
//#include "controller.hpp"
#include "Book.hpp"
#include "Library.hpp"

int main(int argc, char *argv[])
{
    /*
    Library library;
    library.addBook(1234, "Kafka", "Butterflies");
    library.addBook(1134, "Kika", "Bruja");
    library.addBook(1334, "Fall", "Out");
    library.showBooksData();
    */
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    //Controller controller;
    //engine.rootContext()->setContextProperty("controller", &controller);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
