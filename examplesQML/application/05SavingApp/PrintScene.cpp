#include "PrintScene.hpp"

PrintScene::PrintScene(QQmlApplicationEngine &engine, QObject *parent) :
    QObject(parent),
    m_engine(engine),
    m_sceneCreator(engine)
{
    // Constructor implementation
    // QObject::connect(&m_sceneCreator, SIGNAL(buttonClicked()), this, SLOT(prueba()));
}

void PrintScene::paintInterface()
{
    paintControls();
    paintTextInterface();
}

void PrintScene::updateInterface()
{
    // Puedes implementar la lógica de actualización aquí si es necesario
}

QVector<QQuickItem *> PrintScene::getColumnQQuickItem()
{
    return m_columnQQuickItem;
}

QVector<QQuickItem *> PrintScene::getRowQQuickItem()
{
    return m_rowQQuickItem;
}

QVector<QQuickItem *> PrintScene::getTextQQuickItem()
{
    return m_textQQuickItem;
}

QVector<QQuickItem *> PrintScene::getTextFieldQQuickItem()
{
    return m_textFieldQQuickItem;
}

std::map<UIButtonType, QQuickItem *> PrintScene::getButtonQQuickItem()
{
    return m_buttonQQuickItem;
}

std::map<UIComboBoxType, QQuickItem *> PrintScene::getComboBoxQQuickItem()
{
    return m_comboBoxQQuickItem;
}

void PrintScene::paintControls()
{
    m_sceneCreator.createColumn(m_columnQQuickItem);
    m_sceneCreator.createRow(m_columnQQuickItem, m_rowQQuickItem, 0);
    m_sceneCreator.createRow(m_columnQQuickItem, m_rowQQuickItem, 0);
    m_sceneCreator.createRow(m_columnQQuickItem, m_rowQQuickItem, 0);
    m_sceneCreator.createRow(m_columnQQuickItem, m_rowQQuickItem, 0);
    m_sceneCreator.createRow(m_columnQQuickItem, m_rowQQuickItem, 0);
    m_sceneCreator.createRow(m_columnQQuickItem, m_rowQQuickItem, 0);
    m_sceneCreator.createComboBox(m_rowQQuickItem, m_comboBoxQQuickItem, UIComboBoxType::Language, 0);
    m_sceneCreator.createComboBox(m_rowQQuickItem, m_comboBoxQQuickItem, UIComboBoxType::Operation, 1);
    m_sceneCreator.createComboBox(m_rowQQuickItem, m_comboBoxQQuickItem, UIComboBoxType::BudgetAllocation, 1);
    m_sceneCreator.createTextField(m_rowQQuickItem, 2);
    m_sceneCreator.createButton(m_rowQQuickItem, m_buttonQQuickItem, UIButtonType::Accept, 3);
    m_sceneCreator.createButton(m_rowQQuickItem, m_buttonQQuickItem, UIButtonType::Reset, 3);
    m_sceneCreator.createTextElement(m_rowQQuickItem, m_textQQuickItem, 4);
}

void PrintScene::paintTextInterface()
{
    std::map<Vocabulary, QString> word;
    QStringList modelListLanguage;
    QStringList modelListFinances;
    QStringList modelListItems;

    // Assuming that m_buttonQQuickItem and m_comboBoxQQuickItem are not null
    if (!m_buttonQQuickItem.empty() && !m_comboBoxQQuickItem.empty()) {
        word = m_wordBook.getLanguage(Languages::English);

        // Example of accessing elements using at() instead of []
        modelListLanguage << word[Vocabulary::EnglishWord] << word[Vocabulary::SpanishWord];
        QQmlProperty(m_comboBoxQQuickItem.at(UIComboBoxType::Language), "model").write(QVariant::fromValue(modelListLanguage));

        modelListFinances << word[Vocabulary::FundWord] << word[Vocabulary::ExpenseWord];
        QQmlProperty(m_comboBoxQQuickItem.at(UIComboBoxType::Operation), "model").write(QVariant::fromValue(modelListFinances));

        modelListItems << word[Vocabulary::SavingsWord] << word[Vocabulary::HousingWord] << word[Vocabulary::FoodWord]
                       << word[Vocabulary::TransportationWord] << word[Vocabulary::EntertainmentWord]
                       << word[Vocabulary::TravelWord] << word[Vocabulary::ClothingWord] << word[Vocabulary::DebtsWord]
                       << word[Vocabulary::CarWord];
        QQmlProperty(m_comboBoxQQuickItem.at(UIComboBoxType::BudgetAllocation), "model").write(QVariant::fromValue(modelListItems));

        m_buttonQQuickItem.at(UIButtonType::Accept)->setProperty("text", word[Vocabulary::AcceptWord]);
        m_buttonQQuickItem.at(UIButtonType::Reset)->setProperty("text", word[Vocabulary::ResetWord]);
    }
}
