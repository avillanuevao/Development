// sceneCreator.cpp
#include "sceneCreator.hpp"

SceneCreator::SceneCreator(QQmlApplicationEngine &engine, QObject *parent) :
    QObject(parent),
    engine(engine),
    buttonCreator(engine),
    comboBoxCreator(engine),
    rectangleCreator(engine)
{
    // Constructor implementation
}

void SceneCreator::createScene(QString property, int height, int width, QVector<QString> textButton, QVector<QString> comboContainer)
{
    comboBoxCreator.createComboBox(property, height, width, comboContainer);
    for(int i = 0; i < textButton.size(); i++)
    {
        buttonCreator.createButton(property, height, width, textButton.at(i));
    }
    rectangleCreator.createRectangle(property, height, width * 0.8);
    rectangleCreator.createRectangle(property, height, width * 0.5);
}

void SceneCreator::removePreviousScene(QString property, QString objectNameNotRemoveA, QString objectNameNotRemoveB)
{
    QObject *rootObject = engine.rootObjects().first();
    QObject *qmlObject = rootObject->property(property.toStdString().c_str()).value<QObject*>();

    if(qmlObject)
    {
        QQmlComponent button(&engine, QUrl("qrc:/button.qml"));
        QQuickItem *object = qobject_cast<QQuickItem*>(qmlObject);

        if(object)
        {
            QList<QQuickItem *> childItems = object->childItems();
            for (QQuickItem *child : childItems) {
                if (child->objectName() != objectNameNotRemoveA && child->objectName() != objectNameNotRemoveB) {
                    child->deleteLater();
                }
            }

        }
    }
}

void SceneCreator::createSceneMoneyBackground()
{
    QVector<QString> textButton = {"Add", "Reset", "Update"};
    QVector<QString> comboContainer = {"Saving", "Travel", "Car"};
    removePreviousScene("gridLayout", "item1ON", "item2ON");
    createScene("gridLayout", 100, 200, textButton, comboContainer);
}

void SceneCreator::createSceneExpenses()
{
    QVector<QString> textButton = {"Ingredientes", "Cocinar", "Menú", "Supervisar", "Inventario", "Calidad", "Colaborar", "Higiene"};
    removePreviousScene("gridLayout", "item1ON", "item2ON");
    //createScene("gridLayout", 100, 200, textButton);
}

