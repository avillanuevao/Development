#include "scene.hpp"
#include "yourobject.hpp"
#include "colorEnum.hpp"
#include <QQuickItem>
#include <QQuickWindow>
#include <QRandomGenerator>
#include <cmath> // Incluir la librería para utilizar funciones matemáticas como floor


scene::scene(QQmlApplicationEngine &engine, QObject *parent) : engine(engine), QObject(parent) {}


void scene::create_rect_object(const QVector<int>& parameters, const Color::Colors color) {
    QQmlComponent component(&engine, QUrl("qrc:/myrect.qml"));
    QQmlComponent button(&engine, QUrl("qrc:/mybutton.qml"));

    int rectWidth = parameters.at(0); // Ancho de cada rectángulo
    int rectHeight = parameters.at(1); // Altura de cada rectángulo

    int spacing = 10; // Espacio entre rectángulos

    QObject *rootObject = engine.rootObjects().first();
    QObject *qmlColumnLayout = rootObject->property("rowLayout").value<QObject*>();

    if (qmlColumnLayout) {
        QQuickItem *columnLayout = qobject_cast<QQuickItem*>(qmlColumnLayout);

        // Continuación del código para crear un rectángulo y añadirlo al ColumnLayout
        QQmlComponent component(&engine, QUrl("qrc:/myrect.qml"));
        QQmlComponent button(&engine, QUrl("qrc:/mybutton.qml"));

        QObject *object = component.create();
        QQuickItem *item = qobject_cast<QQuickItem*>(object);

        if (columnLayout) {
            item->setParentItem(columnLayout);

            Color colorP;
            QString colorString = colorP.colorsToString(color);

            item->setProperty("color", colorString);
            item->setWidth(rectWidth);
            item->setHeight(rectHeight);
        } else {
            qDebug() << "ColumnLayout not found or invalid.";
            // Manejar la situación si no se encuentra el ColumnLayout
        }
    } else {
        qDebug() << "ColumnLayout not found or invalid.";
        // Manejar la situación si no se encuentra el ColumnLayout
    }
}




/*


        QObject *object = button.create();
        QQuickItem *item = qobject_cast<QQuickItem*>(object);
        item1->setParentItem((QQuickItem*)((QQuickWindow*)engine.rootObjects()[0])->contentItem());
        item1->setWidth(rectWidth);
        item1->setHeight(rectHeight);
        item1->setX(100);
        item1->setY(200);


        YourObject *yourObject = new YourObject(); // Crear una instancia de tu clase personalizada

        // Conectar la señal 'clicked' del botón QML con la ranura 'yourSlot' de YourObject
        QObject::connect(item1, SIGNAL(clicked()), yourObject, SLOT(yourSlot()));

        --

        QObject *object = component.create();
        QQuickItem *item = qobject_cast<QQuickItem*>(object);
        item->setParentItem((QQuickItem*)((QQuickWindow*)engine.rootObjects()[parentItem])->findChild<QQuickItem*>("columnLayout"));
        Color colorP;
        QString colorString = colorP.colorsToString(color);

        item->setProperty("color", colorString);
        item->setWidth(rectWidth);
        item->setHeight(rectHeight);
*/
