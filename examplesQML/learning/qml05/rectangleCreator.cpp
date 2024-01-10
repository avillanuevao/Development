#include "rectangleCreator.hpp"
#include "textContainerCreator.hpp"

RectangleCreator::RectangleCreator(QQmlApplicationEngine &engine, QObject *parent) : engine(engine), QObject(parent){}

void RectangleCreator::createRectangle(const char* property)
{
    QObject *rootObject = engine.rootObjects().first();
    QObject *qmlObject = rootObject->property(property).value<QObject*>();

    if(qmlObject)
    {
        QQmlComponent rectangle(&engine, QUrl("qrc:/rectangle.qml"));
        QQuickItem *object = qobject_cast<QQuickItem*>(qmlObject);
        QObject * rectangleCreate = rectangle.create();
        QQuickItem *item = qobject_cast<QQuickItem*>(rectangleCreate);

        qDebug() << item;
        if(object)
        {
            item->setParentItem(object);
            item->setWidth(200);
            item->setHeight(100);
            item->setZ(0);
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }else
    {
        qDebug() << "qmlObject not found";
    }
}
