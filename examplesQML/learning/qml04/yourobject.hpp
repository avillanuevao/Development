#pragma once

#include <QObject>

class YourObject : public QObject {
    Q_OBJECT

public slots:
    void yourSlot() {
        // Acciones que deseas realizar cuando se haga clic en el botón
        qDebug() << "Botón pulsado!";
        // Otra lógica aquí
    }
};
