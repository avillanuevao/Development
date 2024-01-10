// buttonCreator.cpp
#include "itemCreator.hpp"

ItemCreator::ItemCreator(QQmlApplicationEngine &engine, QObject *parent) :
    QObject(parent),
    engine(engine),
    buttonHandler(std::unique_ptr<ButtonHandler>(new ButtonHandler()))
{
    // Constructor implementation
}


void ItemCreator::createItem(QString property, int columnSpan, int rowSpan, bool fill) {
    QObject *rootObject = engine.rootObjects().first();
    QObject *qmlObject = rootObject->property(property.toStdString().c_str()).value<QObject*>();

    if (qmlObject) {
        QQmlComponent itemComponent(&engine, QUrl("qrc:/item.qml"));
        QObject *itemObject = itemComponent.create();

        if (itemObject) {
            QQuickItem *item = qobject_cast<QQuickItem*>(itemObject);
            item->setParentItem(qobject_cast<QQuickItem*>(qmlObject));
            item->setProperty("width", 100);
            item->setProperty("height", 200);

            QQmlComponent buttonComponent(&engine, QUrl("qrc:/button.qml"));
            QObject *buttonObject = buttonComponent.create();

            if (buttonObject) {
                QQuickItem *buttonItem = qobject_cast<QQuickItem*>(buttonObject);
                buttonItem->setParentItem(item);
                buttonItem->setProperty("width", 100);
                buttonItem->setProperty("height", 200);

                buttonItem->setProperty("text", "textButton");

                ButtonHandler *buttonHandler = new ButtonHandler();
                QObject::connect(buttonItem, SIGNAL(clicked()), buttonHandler, SLOT(handleButtonClickTry()));
            } else {
                qDebug() << "Failed to create button item";
            }
        } else {
            qDebug() << "Failed to create item or qmlObject not found";
        }
    } else {
        qDebug() << "qmlObject not found";
    }
}


