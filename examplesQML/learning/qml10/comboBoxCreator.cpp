// comboBoxCreator.cpp
#include "comboBoxCreator.hpp"

ComboBoxCreator::ComboBoxCreator(QQmlApplicationEngine &engine, QObject *parent) :
    QObject(parent),
    engine(engine)
{
    // Constructor implementation
}


void ComboBoxCreator::createComboBox(QString property, int height, int width, QVector<QString> comboContainer)
{
    // Función para crear el botón con las propiedades dadas
    // Usa 'engine' para crear el botón utilizando QML
    QObject *rootObject = engine.rootObjects().first();
    QObject *qmlObject = rootObject->property(property.toStdString().c_str()).value<QObject*>();

    if(qmlObject)
    {
        QQmlComponent button(&engine, QUrl("qrc:/comboBox.qml"));
        QQuickItem *object = qobject_cast<QQuickItem*>(qmlObject);
        QObject * buttonCreate = button.create();
        QQuickItem *item = qobject_cast<QQuickItem*>(buttonCreate);

        qDebug() << item;
        if(object)
        {
            item->setParentItem(object);
            item->setWidth(width);
            item->setHeight(height);
            QStringListModel model;
            QStringList list;

            for(int i = 0; i < comboContainer.size(); i++)
            {
                list << comboContainer[i];
            }
            model.setStringList(list);
            item->setProperty("model", list);
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }else
    {
        qDebug() << "qmlObject not found";
    }
}
