// RectangleCreator.cpp
#include "rectangleCreator.hpp"

RectangleCreator::RectangleCreator(QQmlApplicationEngine &engine, QObject *parent) :
    QObject(parent),
    engine(engine)
{
    // Constructor implementation
}


void RectangleCreator::createRectangle(QString property, int height, int width)
{
    // Función para crear el botón con las propiedades dadas
    // Usa 'engine' para crear el botón utilizando QML
    QObject *rootObject = engine.rootObjects().first();
    QObject *qmlObject = rootObject->property(property.toStdString().c_str()).value<QObject*>();

    if(qmlObject)
    {
        QQmlComponent button(&engine, QUrl("qrc:/rectangle.qml"));
        QQuickItem *object = qobject_cast<QQuickItem*>(qmlObject);
        QObject * buttonCreate = button.create();
        QQuickItem *item = qobject_cast<QQuickItem*>(buttonCreate);

        qDebug() << item;
        if(object)
        {

            item->setParentItem(object);
            item->setWidth(width);
            item->setHeight(height);

            //QTimer::singleShot(5000, item, &QObject::deleteLater);
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }else
    {
        qDebug() << "qmlObject not found";
    }
}
