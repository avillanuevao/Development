#ifndef MYCONTROLLER_H
#define MYCONTROLLER_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QVector>

#include <iostream>

class MyController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString showButtonText READ getShowButtonText WRITE setShowButtonText NOTIFY showButtonTextChanged)
    Q_PROPERTY(QString addButtonText READ getAddButtonText WRITE setAddButtonText NOTIFY addButtonTextChanged)
    Q_PROPERTY(QString deleteButtonText READ getDeleteButtonText WRITE setDeleteButtonText NOTIFY deleteButtonTextChanged)
    Q_PROPERTY(QString saveButtonText READ getSaveButtonText WRITE setSaveButtonText NOTIFY saveButtonTextChanged)
    Q_PROPERTY(QString mbButtonText READ getMbButtonText WRITE setMbButtonText NOTIFY mbButtonTextChanged)
    Q_PROPERTY(QString expButtonText READ getExpButtonText WRITE setExpButtonText NOTIFY expButtonTextChanged)
    Q_PROPERTY(QString mbTextFieldV READ getMbTextFieldV WRITE setMbTextFieldV NOTIFY mbTextFieldVChanged)
    Q_PROPERTY(int bmShowed READ getBmShowed WRITE setBmShowed NOTIFY bmShowedChanged)
    Q_PROPERTY(int expShowed READ getExpShowed WRITE setExpShowed NOTIFY expShowedChanged)
    Q_PROPERTY(QVector<QString> savingType READ getSavingType WRITE setSavingType NOTIFY savingTypeChanged)
    Q_PROPERTY(QVector<QString> monthType READ getMonthType WRITE setMonthType NOTIFY monthTypeChanged)
    Q_PROPERTY(QVector<int> mbQuantity READ getMbQuantity WRITE setMbQuantity NOTIFY mbQuantityChanged)
    Q_PROPERTY(QVector<int> expQuantity READ getExpQuantity WRITE setExpQuantity NOTIFY expQuantityChanged)


public:
    explicit MyController(QObject *parent = nullptr);

    QString getShowButtonText() const;
    void setShowButtonText(QString newValue);

    QString getAddButtonText() const;
    void setAddButtonText(QString newValue);

    QString getDeleteButtonText() const;
    void setDeleteButtonText(QString newValue);

    QString getSaveButtonText() const;
    void setSaveButtonText(QString newValue);

    QString getMbButtonText() const;
    void setMbButtonText(QString newValue);

    QString getExpButtonText() const;
    void setExpButtonText(QString newValue);

    QString getMbTextFieldV() const;
    void setMbTextFieldV(QString newValue);

    int getBmShowed() const;
    void setBmShowed(int newValue);

    int getExpShowed() const;
    void setExpShowed(int newValue);

    QVector<QString> getSavingType() const;
    void setSavingType(QVector<QString> newValue);

    QVector<QString> getMonthType() const;
    void setMonthType(QVector<QString> newValue);

    QVector<int> getMbQuantity() const;
    void setMbQuantity(QVector<int> newValue);

    QVector<int> getExpQuantity() const;
    void setExpQuantity(QVector<int> newValue);

public slots:
    void updateMbQuantity(int position, int newValue);
    void updateExpQuantity(int position, int newValue);


signals:
    void showButtonTextChanged();
    void addButtonTextChanged();
    void deleteButtonTextChanged();
    void saveButtonTextChanged();
    void mbButtonTextChanged();
    void expButtonTextChanged();
    void mbTextFieldVChanged();
    void bmShowedChanged();
    void expShowedChanged();
    void savingTypeChanged();
    void monthTypeChanged();
    void mbQuantityChanged();
    void expQuantityChanged();

private:
    QString m_showButtonText;
    QString m_addButtonText;
    QString m_deleteButtonText;
    QString m_saveButtonText;
    QString m_mbButtonText;
    QString m_expButtonText;
    QString m_mbTextFieldV;
    int m_bmShowed;
    int m_expShowed;
    QVector<QString> m_savingType;
    QVector<QString> m_monthType;
    QVector<int> m_mbQuantity;
    QVector<int> m_expQuantity;


};

#endif // MYCONTROLLER_H
