#include "textContainerCreator.hpp"

TextContainerCreator::TextContainerCreator(QQmlApplicationEngine &engine, QObject *parent) : engine(engine), QObject(parent){}

void TextContainerCreator::createTextContainer(const char* property)
{
    QObject *rootObject = engine.rootObjects().first();
    QObject *qmlObject = rootObject->property(property).value<QObject*>();

    if(qmlObject)
    {
        QQmlComponent textContainer(&engine, QUrl("qrc:/textContainer.qml"));
        QQuickItem *object = qobject_cast<QQuickItem*>(qmlObject);
        QObject * textContainerCreate = textContainer.create();
        QQuickItem *item = qobject_cast<QQuickItem*>(textContainerCreate);

        if(object)
        {
            item->setParentItem(object);
            item->setWidth(200);
            item->setHeight(100);
            item->setZ(1);
            QQmlProperty(item, "text").write("text");
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }else
    {
        qDebug() << "qmlObject not found";
    }
}
