#include "SceneCreator.hpp"

SceneCreator::SceneCreator(QQmlApplicationEngine &engine, QObject *parent) :
    QObject(parent),
    m_engine(engine)
{
    // Constructor implementation
}

void SceneCreator::createScene()
{
    createColumn();
    createRow(m_itemIDColumn, 0);
    createRow(m_itemIDColumn, 0);
    createRow(m_itemIDColumn, 0);
    createRow(m_itemIDColumn, 0);
    createRow(m_itemIDColumn, 0);
    createRow(m_itemIDColumn, 0);
    createComboBox(UIItemType::Language, m_itemIDRow, 0);
    createComboBox(UIItemType::Transaction, m_itemIDRow, 1);
    createComboBox(UIItemType::Bucket, m_itemIDRow, 1);
    createTextField(m_itemIDRow, 2);
    createButton(UIButtonType::Accept, m_itemIDRow, 3);
    createButton(UIButtonType::Reset, m_itemIDRow, 3);
    createTextElement(m_itemIDRow, 4);
    initializeTextLanguage();
}
//Las funciones tienen cohesion con la clase --> en este caso no, ya que ha sido creada para CREAR
    //todas las funciones y atributos tengan relaciones entre si
//Dividir con cierto orden -> MVC
    //modelo selectBucket + amountMoney + SelectedType
//Devuelve clase que contiene los botones --> la clase devuelta es la vista

void SceneCreator::handleButtonClicked()
{
    // Obtener el objeto QQuickItem del que se originó la señal
    QQuickItem *clickedButton = qobject_cast<QQuickItem*>(sender());
    // Verificar si se obtuvo con éxito el objeto QQuickItem
    if (clickedButton)
    {
        // Obtener el valor de la propiedad "id" del botón
        int buttonId = clickedButton->property("id").toInt();
        //Acciones basadas en el tipo de botón
        switch (buttonId) {
        //Logica a otra zona, ya que no solo manejo el boton
        case UIButtonType::Accept:
            //funcion controlador
            switch (m_selectedType) {
            case UITransactionType::Fund:
                m_AppController.setFund(m_selectedBucket, m_amountMoney);
                break;
            case UITransactionType::Expense:
                m_AppController.setExpense(m_selectedBucket, m_amountMoney);
                break;
            }
            break;
        case UIButtonType::Reset:
            m_AppController.resetBucketType(m_selectedBucket);
            break;
        }
        //otro individuo ha de modificar
        modifyTextElement(m_AppController.getMoneyBalance(m_selectedBucket));
    }
    else
    {
        qDebug() << "clickedButton not found";
    }
}

void SceneCreator::handleCurrentIndexChanged()
{
    // Obtiene el objeto que envió la señal
    QObject* senderObject = QObject::sender();
    // Intenta convertir el objeto a un QQuickItem
    QQuickItem* comboBoxItem = qobject_cast<QQuickItem*>(senderObject);
    // Verifica si la conversión fue exitosa
    if (comboBoxItem)
    {
        // Obtiene el valor de la propiedad "id" del ComboBox
        int comboBoxId = comboBoxItem->property("id").toInt();
        switch (comboBoxId) {
        case UIItemType::Transaction:
            m_selectedType = comboBoxItem->property("currentIndex").toInt();
            break;
        case UIItemType::Bucket:
            m_selectedBucket = comboBoxItem->property("currentIndex").toInt();
            modifyTextElement(m_AppController.getMoneyBalance(m_selectedBucket));
            break;
        case UIItemType::Language:
            m_selectedLanguage = comboBoxItem->property("currentIndex").toInt();
            setTextLanguage();
            break;
        }
    }
    else
    {
        qDebug() << "ComboBox not found";
    }
}

void SceneCreator::handleNumericTextChanged()
{
    // Obtiene el objeto que envió la señal
    QObject* senderObject = QObject::sender();
    // Intenta convertir el objeto a un QQuickItem
    QQuickItem* textFieldItem = qobject_cast<QQuickItem*>(senderObject);
    // Verifica si la conversión fue exitosa
    if (textFieldItem)
    {
        QString textFieldText = textFieldItem->property("text").toString();
        m_amountMoney = textFieldText.toInt();
    }
    else
    {
        qDebug() << "TextField Object not found";
    }
}

void SceneCreator::createColumn()
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
            m_itemIDColumn.push_back(componentItem);
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void SceneCreator::createRow(QVector<QQuickItem*> parent, int parentID)
{
    if(m_itemIDColumn[0])
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
            m_itemIDRow.push_back(componentItem);
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void SceneCreator::createButton(UIButtonType idButton, QVector<QQuickItem*> parent, int parentID)
{
    if(m_itemIDRow[2])
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
            m_buttonIdContainter[idButton] = componentItem;
            connect(componentItem, SIGNAL(clicked()), this, SLOT(handleButtonClicked()));
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void SceneCreator::createComboBox(UIItemType idComboBox, QVector<QQuickItem*> parent, int parentID)
{
    if(m_itemIDRow[0])
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
            m_comboBoxIdContainter[idComboBox] = componentItem;
            connect(componentItem, SIGNAL(currentIndexChanged()), this, SLOT(handleCurrentIndexChanged()));
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void SceneCreator::createTextField(QVector<QQuickItem*> parent, int parentID)
{
    if(m_itemIDRow[1])
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
            connect(componentItem, SIGNAL(textChanged()), this, SLOT(handleNumericTextChanged()));
        }else
        {
            qDebug() << "qmlObject not found";
        }
    }
}

void SceneCreator::createTextElement(QVector<QQuickItem *> parent, int parentID)
{
    if (m_itemIDRow[3])
    {
        QQmlComponent component(&m_engine);
        QString qmlCode = "import QtQuick 2.15; import QtQuick.Controls 2.15; Text { }";
        component.setData(qmlCode.toUtf8(), QUrl());

        QObject* componentCreate = component.create();
        QQuickItem* componentItem = qobject_cast<QQuickItem*>(componentCreate);
        m_textElement.push_back(componentItem);
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

void SceneCreator::modifyTextElement(int newText)
{
    if (m_textElement.at(0))
    {
        QString bucketType = m_AppController.bucketTypeformIntToQString(m_selectedBucket);
        QString message = bucketType + ": " + QString::number(newText);
        m_textElement.at(0)->setProperty("text", message);
    }
    else
    {
        qDebug() << "Text Element not found";
    }
}

void SceneCreator::initializeTextLanguage()
{
    std::map<Vocabulary, QString> word = m_WordBook.getLanguage(Languages::English);
    QStringList modelListLanguage;
    modelListLanguage << word[Vocabulary::EnglishWord] << word[Vocabulary::SpanishWord];
    QQmlProperty(m_comboBoxIdContainter[UIItemType::Language], "model").write(QVariant::fromValue(modelListLanguage));
    setTextLanguage();
}

void SceneCreator::setTextLanguage()
{
    std::map<Vocabulary, QString> word;
    QStringList modelListFinances;
    QStringList modelListItems;

    switch (m_selectedLanguage) {
    case 0:
        word = m_WordBook.getLanguage(Languages::English);
        break;
    case 1:
        word = m_WordBook.getLanguage(Languages::Spanish);
        break;
    }
    modelListFinances << word[Vocabulary::FundWord] << word[Vocabulary::ExpenseWord];
    QQmlProperty(m_comboBoxIdContainter[UIItemType::Transaction], "model").write(QVariant::fromValue(modelListFinances));

    modelListItems << word[Vocabulary::SavingsWord] << word[Vocabulary::HousingWord] << word[Vocabulary::FoodWord]<< word[Vocabulary::TransportationWord] << word[Vocabulary::EntertainmentWord] << word[Vocabulary::TravelWord] << word[Vocabulary::ClothingWord] << word[Vocabulary::DebtsWord] << word[Vocabulary::CarWord];
    QQmlProperty(m_comboBoxIdContainter[UIItemType::Bucket], "model").write(QVariant::fromValue(modelListItems));

    m_buttonIdContainter[UIButtonType::Accept]->setProperty("text", word[Vocabulary::AcceptWord]);
    m_buttonIdContainter[UIButtonType::Reset]->setProperty("text", word[Vocabulary::ResetWord]);
}
