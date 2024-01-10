#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double mbSaving READ getMbSaving WRITE setMbSaving NOTIFY mbSavingChanged);
    Q_PROPERTY(double expSaving READ getExpSaving WRITE setExpSaving NOTIFY expSavingChanged);

    Q_PROPERTY(double mbCar READ getMbCar WRITE setMbCar NOTIFY mbCarChanged);
    Q_PROPERTY(double expCar READ getExpCar WRITE setExpCar NOTIFY expCarChanged);

    Q_PROPERTY(double mbTravel READ getMbTravel WRITE setMbTravel NOTIFY mbTravelChanged);
    Q_PROPERTY(double expTravel READ getExpTravel WRITE setExpTravel NOTIFY expTravelChanged);

    Q_PROPERTY(double mbRest READ getMbRest WRITE setMbRest NOTIFY mbRestChanged);
    Q_PROPERTY(double expRest READ getExpRest WRITE setExpRest NOTIFY expRestChanged);



public:
    explicit Controller(QObject *parent = nullptr);


public slots:
    double getMbSaving();
    double getExpSaving();

    double getMbCar();
    double getExpCar();

    double getMbTravel();
    double getExpTravel();

    double getMbRest();
    double getExpRest();

    void setMbSaving(double newValue);
    void setExpSaving(double newValue);

    void setMbCar(double newValue);
    void setExpCar(double newValue);

    void setMbTravel(double newValue);
    void setExpTravel(double newValue);

    void setMbRest(double newValue);
    void setExpRest(double newValue);

signals:
    void mbSavingChanged();
    void expSavingChanged();

    void mbCarChanged();
    void expCarChanged();

    void mbTravelChanged();
    void expTravelChanged();

    void mbRestChanged();
    void expRestChanged();


private:
    double m_mbSaving;
    double m_mbCar;
    double m_mbTravel;
    double m_mbRest;

    double m_expSaving;
    double m_expCar;
    double m_expTravel;
    double m_expRest;

    double m_balanceSaving;
    double m_balanceCar;
    double m_balanceTravel;
    double m_balanceRest;

    void loadFromJsonFile(const QString &filename);
    //void modifyJsonFile(const QString &filename, int type, int element);
};

#endif // CONTROLLER_H
