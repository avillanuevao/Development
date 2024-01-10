#include "controller.hpp"

Controller::Controller(QObject *parent) : QObject(parent), m_mbSaving(0), m_expSaving(0),
    m_mbCar(0), m_expCar(0),
    m_mbTravel(0), m_expTravel(0),
    m_mbRest(0), m_expRest(0),
    m_balanceSaving(0), m_balanceCar(0), m_balanceTravel(0), m_balanceRest(0){
    loadFromJsonFile("/home/blindados/workspace/qml03/dataBase.json");
}

double Controller::getMbSaving()
{
    return m_mbSaving;
}

double Controller::getExpSaving()
{
    return m_expSaving;
}

double Controller::getMbCar()
{
    return m_mbCar;
}

double Controller::getExpCar()
{
    return m_expCar;
}

double Controller::getMbTravel()
{
    return m_mbTravel;
}

double Controller::getExpTravel()
{
    return m_expTravel;
}

double Controller::getMbRest()
{
    return m_mbRest;
}

double Controller::getExpRest()
{
    return m_expRest;
}

void Controller::setMbSaving(double newValue)
{
    qDebug() << "Entra en setMbSaving";
    if(newValue == 0.0)
    {
        m_mbSaving = newValue;
        setExpSaving(0.0);
        emit mbSavingChanged();
    } else if(newValue > 0.0){
        m_mbSaving = newValue;
        emit mbSavingChanged();
    }
    qDebug() << "setMbSaving " << m_mbSaving;
    //modifyJsonFile("/home/blindados/workspace/qml03/dataBase.json", 0, 0);
}

void Controller::setExpSaving(double newValue)
{
    qDebug() << "Entra en setExpSaving";
    if(newValue == 0.0)
    {
        m_expSaving = newValue;
        emit expSavingChanged();
    }else if(newValue > 0)
    {
        if(m_mbSaving >= (m_expSaving + newValue))
        {
            m_expSaving += newValue;
            emit expSavingChanged();
        }
    }
}

void Controller::setMbCar(double newValue)
{
    qDebug() << "Entra en setMbCar";
    if(newValue == 0.0)
    {
        m_mbCar = newValue;
        setExpCar(0.0);
        emit mbCarChanged();
    }else if(newValue > 0.0)
    {
        m_mbCar = newValue;
        emit mbCarChanged();
    }
}

void Controller::setExpCar(double newValue)
{
    qDebug() << "Entra en setExpCar";
    if(newValue == 0.0)
    {
        m_expCar = newValue;
        emit expCarChanged();
    }else if(newValue > 0)
    {
        if(m_mbCar >= (m_expCar + newValue))
        {
            m_expCar += newValue;
            emit expCarChanged();
        }
    }
}

void Controller::setMbTravel(double newValue)
{
    qDebug() << "Entra en setMbTravel";
    if(newValue == 0.0)
    {
        m_mbTravel = newValue;
        setExpTravel(0.0);
        emit mbTravelChanged();
    }else if(newValue > 0.0)
    {
        m_mbTravel = newValue;
        emit mbTravelChanged();
    }
}

void Controller::setExpTravel(double newValue)
{
    qDebug() << "setExpTravel";

    if(newValue == 0.0)
    {
        m_expTravel = newValue;
        emit expTravelChanged();
    }else if(newValue > 0)
    {
        if(m_mbTravel >= (m_expTravel + newValue))
        {
            m_expTravel += newValue;
            emit expTravelChanged();
        }
    }
}

void Controller::setMbRest(double newValue)
{
    qDebug() << "Entra en setMbRest";
    if(newValue == 0.0)
    {
        m_mbRest = newValue;
        setExpRest(0.0);
        emit mbRestChanged();
    }else if(newValue > 0.0)
    {
        m_mbRest = newValue;
        emit mbRestChanged();
    }
}

void Controller::setExpRest(double newValue)
{
    qDebug() << "Entra en setExpRest";
    if(newValue == 0.0)
    {
        qDebug() << "Entra en setExpRest 0";

        m_expRest = newValue;
        emit expRestChanged();
    }else if(newValue > 0)
    {
        qDebug() << "Entra en setExpRest > 0";

        if(m_mbRest >= (m_expRest + newValue))
        {
            qDebug() << "Entra en setExpRest val";

            m_expRest += newValue;
            emit expRestChanged();
        }
    }
}

void Controller::loadFromJsonFile(const QString &filename)
{
    qDebug() << "Intentando abrir el archivo JSON";

    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error al abrir el archivo JSON";
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "Error al analizar el archivo JSON";
        qDebug() << parseError.errorString();
        return;
    }

    if (doc.isObject()) {
        QJsonObject jsonObject = doc.object();

        if (jsonObject.contains("mb") && jsonObject["mb"].isObject()) {
            QJsonObject mbObject = jsonObject["mb"].toObject();

            m_mbSaving = mbObject.value("saving").toInt();
            m_mbCar = mbObject.value("car").toInt();
            m_mbTravel = mbObject.value("travel").toInt();
            m_mbRest = mbObject.value("rest").toInt();
            qDebug() << "Carga exitosa desde el archivo JSON";
        }
    }
    else{
        qDebug() << "No abierto";
    }
}


/*
void Controller::modifyJsonFile(const QString &filename, int type, int element)
{
    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Manejar error al abrir el archivo
        qDebug() << "Error al abrir el archivo.";
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        // Manejar error al analizar el JSON
        qDebug() << "Error al analizar el JSON.";
        return;
    }

    if(doc.isObject())
    {
        QJsonObject jsonObject = doc.object();

        switch (type) {
            case 0: //mb
                if (jsonObject.contains("mb") && jsonObject["mb"].isObject()) {
                QJsonObject mbObject = jsonObject["mb"].toObject();
                switch (element) {
                    case 0: //saving
                        if (mbObject.contains("saving") && mbObject["saving"].isDouble()) {
                            mbObject["saving"] = m_mbSaving;
                            qDebug() << mbObject["saving"] << " " << m_mbSaving;
                            QFile writeFile(filename);

                            if (writeFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
                                QJsonDocument doc(jsonObject);
                                writeFile.write(doc.toJson());
                                writeFile.close();
                                qDebug() << "Archivo modificado exitosamente.";
                            } else {
                                qDebug() << "Error al escribir en el archivo.";
                            }

                        }
                        break;
                    case 1: //car

                        break;
                    case 2: //travel

                        break;
                    case 3: //rest

                        break;
                }
                }
                break;
            case 1: //exp
                switch (element) {
                    case 0: //saving
                        break;
                    case 1: //car
                        break;
                    case 2: //travel
                        break;
                    case 3: //rest
                        break;
                }
                break;
        }
    }
}
*/
