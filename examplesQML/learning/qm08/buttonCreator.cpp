// buttonCreator.cpp
#include "buttonCreator.hpp"

ButtonCreator::ButtonCreator(QQmlApplicationEngine &engine, QObject *parent) :
    QObject(parent),
    engine(engine),
    buttonHandler(std::unique_ptr<ButtonHandler>(new ButtonHandler()))
{
    // Constructor implementation
}


void ButtonCreator::createButton(QString property, int height, int width, QString textButton)
{
    // Función para crear el botón con las propiedades dadas
    // Usa 'engine' para crear el botón utilizando QML
    QObject *rootObject = engine.rootObjects().first();
    QObject *qmlObject = rootObject->property(property.toStdString().c_str()).value<QObject*>();

    if(qmlObject)
    {
        QQmlComponent button(&engine, QUrl("qrc:/button.qml"));
        QQuickItem *object = qobject_cast<QQuickItem*>(qmlObject);
        QObject * buttonCreate = button.create();
        QQuickItem *item = qobject_cast<QQuickItem*>(buttonCreate);

        qDebug() << item;
        if(object)
        {
            item->setParentItem(object);
            item->setWidth(width);
            item->setHeight(height);
            item->setProperty("text", textButton);
            item->setProperty("Layout.columnSpan", 2);
        }else
        {
            qDebug() << "qmlObject not found";
        }
        ButtonHandler * buttonHandler = new ButtonHandler();

        QObject::connect(item, SIGNAL(clicked()), buttonHandler, SLOT(handleButtonClickTry()));
    }else
    {
        qDebug() << "qmlObject not found";
    }
}
