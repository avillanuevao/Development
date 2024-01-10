#include "SceneCreator.hpp"

SceneCreator::SceneCreator(QQmlApplicationEngine &engine, QObject *parent) :
    QObject(parent),
    m_engine(engine)
{
    // Constructor implementation
}

//Las funciones tienen cohesion con la clase --> en este caso no, ya que ha sido creada para CREAR
//todas las funciones y atributos tengan relaciones entre si
//Dividir con cierto orden -> MVC
//modelo selectBucket + amountMoney + SelectedType
//Devuelve clase que contiene los botones --> la clase devuelta es la vista

QQuickItem *SceneCreator::handler()
{
    qDebug() << "Emision señal";
    emit buttonClicked();
    QQuickItem *signalGenerator = qobject_cast<QQuickItem*>(sender());
    return signalGenerator;
}

void SceneCreator::createColumn(QVector<QQuickItem*>& containter)
{
    QObject* rootObject = m_engine.rootObjects().first();
    QQuickWindow* rootWindow = qobject_cast<QQuickWindow*>(rootObject);
    if(rootWindow)
    {
        QQmlComponent component(&m_engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Layouts 1.15; ColumnLayout{}";
        component.setData(qmlCode.toUtf8(), QUrl());
        QQuickItem *object = qobject_cast<QQuickItem*>(rootWindow->contentItem());
        QObject * componentCreate = component.create();
        QQuickItem *componentItem = qobject_cast<QQuickItem*>(componentCreate);
        if(object)
        {
            componentItem->setParentItem(object);
            containter.push_back(componentItem);
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void SceneCreator::createRow(QVector<QQuickItem*>& parent, QVector<QQuickItem *> &containter, int parentID)
{
    if(parent[parentID])
    {
        QQmlComponent component(&m_engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Layouts 1.15; RowLayout{}";
        component.setData(qmlCode.toUtf8(), QUrl());

        QObject * componentCreate = component.create();
        QQuickItem *componentItem = qobject_cast<QQuickItem*>(componentCreate);
        if(componentItem)
        {
            componentItem->setParent(parent[parentID]);
            componentItem->setParentItem(parent[parentID]);
            containter.push_back(componentItem);
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void SceneCreator::createButton(QVector<QQuickItem*>& parent, std::map<UIButtonType,
                                QQuickItem*>& container, UIButtonType idButton, int parentID)
{
    if(parent[parentID])
    {
        QQmlComponent component(&m_engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Controls 2.15; Button{}";
        component.setData(qmlCode.toUtf8(), QUrl());

        QObject * componentCreate = component.create();
        QQuickItem *componentItem = qobject_cast<QQuickItem*>(componentCreate);
        if(componentItem)
        {
            componentItem->setParent(parent[parentID]);
            componentItem->setParentItem(parent[parentID]);
            componentItem->setProperty("id", idButton);
            container[idButton] = componentItem;
            //connect(componentItem, SIGNAL(clicked()), this, SLOT(handler()));
            //connect(componentItem, SIGNAL(clicked()), this, SIGNAL(buttonClicked()));
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void SceneCreator::createComboBox(QVector<QQuickItem*>& parent, std::map<UIComboBoxType, QQuickItem *> &container, UIComboBoxType idComboBox, int parentID)
{
    if(parent[parentID])
    {
        QQmlComponent component(&m_engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Controls 2.15; ComboBox{}";
        component.setData(qmlCode.toUtf8(), QUrl());

        QObject * componentCreate = component.create();
        QQuickItem *componentItem = qobject_cast<QQuickItem*>(componentCreate);
        if(componentItem)
        {
            componentItem->setParent(parent[parentID]);
            componentItem->setParentItem(parent[parentID]);
            componentItem->setProperty("id", idComboBox);
            container[idComboBox] = componentItem;
            //connect(componentItem, SIGNAL(currentIndexChanged()), this, SIGNAL(buttonClicked()));
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void SceneCreator::createTextField(QVector<QQuickItem *> &parent, int parentID)
{
    if(parent[parentID])
    {
        QQmlComponent component(&m_engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Controls 2.15; TextField{}";
        component.setData(qmlCode.toUtf8(), QUrl());

        QObject * componentCreate = component.create();
        QQuickItem *componentItem = qobject_cast<QQuickItem*>(componentCreate);
        if(componentItem)
        {
            componentItem->setParent(parent[parentID]);
            componentItem->setParentItem(parent[parentID]);
            //containter.push_back(componentItem);
            //connect(componentItem, SIGNAL(textChanged()), this, SIGNAL(buttonClicked()));
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void SceneCreator::createTextElement(QVector<QQuickItem *>& parent, QVector<QQuickItem*>& containter, int parentID)
{
    if (parent[parentID])
    {
        QQmlComponent component(&m_engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Controls 2.15; Text { }";
        component.setData(qmlCode.toUtf8(), QUrl());

        QObject* componentCreate = component.create();
        QQuickItem* componentItem = qobject_cast<QQuickItem*>(componentCreate);
        containter.push_back(componentItem);
        if (componentItem)
        {
            componentItem->setParent(parent[parentID]);
            componentItem->setParentItem(parent[parentID]);
            componentItem->setProperty("text", "0");
        }
        else
        {
            qDebug() << "qmlObject not found";
        }
    }
}
