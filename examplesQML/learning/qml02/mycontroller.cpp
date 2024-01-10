#include "mycontroller.h"

MyController::MyController(QObject *parent): QObject(parent),
    m_showButtonText("Show"),
    m_addButtonText("Add"),
    m_deleteButtonText("Delete"),
    m_saveButtonText("Save"),
    m_mbButtonText("MoneyB"),
    m_expButtonText("Expenses"),
    m_mbTextFieldV("Add"),
    m_bmShowed(0),
    m_expShowed(0),
    m_savingType({"Saving", "Car", "Travel", "Rest"}),
    m_monthType({"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}),
    m_mbQuantity({0, 0, 0, 0}),
    m_expQuantity({0, 0, 0, 0})

    {}

QString MyController::getShowButtonText() const
{
    return m_showButtonText;
}

void MyController::setShowButtonText(QString newValue)
{
    if(m_showButtonText != newValue)
    {
        m_showButtonText = newValue;
        emit showButtonTextChanged();
    }
}

QString MyController::getAddButtonText() const
{
    return m_addButtonText;
}

void MyController::setAddButtonText(QString newValue)
{
    if(m_addButtonText != newValue)
    {
        m_addButtonText = newValue;
        emit addButtonTextChanged();
    }
}

QString MyController::getDeleteButtonText() const
{
    return m_deleteButtonText;
}

void MyController::setDeleteButtonText(QString newValue)
{
    if(m_deleteButtonText != newValue)
    {
        m_deleteButtonText = newValue;
        emit deleteButtonTextChanged();
    }
}

QString MyController::getSaveButtonText() const
{
    return m_saveButtonText;
}

void MyController::setSaveButtonText(QString newValue){
    if(m_saveButtonText != newValue)
    {
        m_saveButtonText = newValue;
        emit saveButtonTextChanged();
    }
}

QString MyController::getMbButtonText() const
{
    return m_mbButtonText;
}

void MyController::setMbButtonText(QString newValue){
    if(m_mbButtonText != newValue)
    {
        m_mbButtonText = newValue;
        emit mbButtonTextChanged();
    }
}

QString MyController::getExpButtonText() const
{
    return m_expButtonText;
}

void MyController::setExpButtonText(QString newValue){
    if(m_expButtonText != newValue)
    {
        m_expButtonText = newValue;
        emit expButtonTextChanged();
    }
}

QString MyController::getMbTextFieldV() const
{
    return m_mbTextFieldV;
}

void MyController::setMbTextFieldV(QString newValue){
    if(m_mbTextFieldV != newValue)
    {
        m_mbTextFieldV = newValue;
        emit mbTextFieldVChanged();
    }
}

int MyController::getBmShowed() const
{
    return m_bmShowed;
}

void MyController::setBmShowed(int newValue){
    if(m_bmShowed != newValue)
    {
        m_bmShowed = newValue;
        emit bmShowedChanged();
    }
}

int MyController::getExpShowed() const
{
    return m_expShowed;
}

void MyController::setExpShowed(int newValue){
    if(m_expShowed != newValue)
    {
        m_expShowed = newValue;
        emit expShowedChanged();
    }
}

QVector<QString> MyController::getSavingType() const
{
    return m_savingType;
}

void MyController::setSavingType(QVector<QString> newValue){
    if(m_savingType != newValue)
    {
        m_savingType = newValue;
        emit savingTypeChanged();
    }
}

QVector<QString> MyController::getMonthType() const
{
    return m_monthType;
}

void MyController::setMonthType(QVector<QString> newValue){
    if(m_monthType != newValue)
    {
        m_monthType = newValue;
        emit monthTypeChanged();
    }
}

QVector<int> MyController::getMbQuantity() const
{
    return m_mbQuantity;
}
void MyController::setMbQuantity(QVector<int> newValue)
{
    if(m_mbQuantity != newValue)
    {
        m_mbQuantity = newValue;
        emit mbQuantityChanged();
    }
}

void MyController::updateMbQuantity(int position, int newValue) {
    if (position >= 0 && position < m_mbQuantity.size()) {
        m_mbQuantity[position] = newValue;
        emit mbQuantityChanged();
    }
}

QVector<int> MyController::getExpQuantity() const
{
    return m_expQuantity;
}

void MyController::setExpQuantity(QVector<int> newExpQuantity)
{
    if(m_expQuantity != newExpQuantity)
    {
        m_expQuantity = newExpQuantity;
        emit expQuantityChanged();
    }
}

void MyController::updateExpQuantity(int position, int newValue)
{
    if (position >= 0 && position < m_expQuantity.size()) {
        m_expQuantity[position] += newValue;
        emit mbQuantityChanged();
    }
}
