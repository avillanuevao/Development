import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15  // Importa los controles básicos, incluyendo Button

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Configurar mes")

    Image {
        source: "images/image01.jpeg"
        width: parent.width
        height: parent.height
    }

    Column {
        anchors.centerIn: parent
        spacing: 10
        Rectangle {
            width: 200
            height: 100
            color: "white"
            radius: 20
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.verticalCenter - 100// Puedes ajustar esto según tu necesidad
            Text {
                text: "Configurar Mes"
                width: parent.width - 40
                anchors.centerIn: parent

            }
        }
        Row {
            ComboBox {
                width: 200
                height: 100
                background: Rectangle {
                    color: "white"
                    radius: 20
                }

                model: ["Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"]
                currentIndex: 0
            }
            Item {
                width: 200
                height: 100
            }
        }
        Button {
            text: "Guardar"
            width: 100
            height: 50
            background: Rectangle {
                color: "white"
                radius: 20
            }
            font.bold: true
            onClicked: {
                console.log("Set the month")
            }
        }
    }
}


