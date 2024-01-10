#include "loader.hpp"
#include <QQmlContext>

QMLLoader::QMLLoader(QObject *parent) : QObject(parent) {
    // Cargar QML inicial
    m_engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (m_engine.rootObjects().isEmpty()) {
        // Manejo de error si no se carga correctamente
    }

    // Obtener el contexto del motor QML
    QQmlContext *context = m_engine.rootContext();

    // Exponer la instancia de esta clase al QML
    context->setContextProperty("qmlLoader", this);
}

void QMLLoader::loadNewQML(const QString &qmlFile) {
    qDebug() << "loadNewQML" << qmlFile;
    //m_engine.load(QUrl(qmlFile));
    //m_engine.load(QUrl(QStringLiteral("qrc:/second.qml")));
}
