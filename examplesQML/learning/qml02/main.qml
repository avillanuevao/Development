import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15  // Importa los controles básicos, incluyendo Button

Window {
    width: Screen.width
    height: Screen.height
    visible: true
    title: qsTr("Hello World")

    //INTERFACE0
    Rectangle {
        id: interface0
        width: parent.width
        height: parent.height
        visible: true

        Image {
            source: "images/image01.jpeg"
            width: parent.width
            height: parent.height
            anchors.fill: parent
        }

        Column {
            anchors.centerIn: parent
            spacing: 10
            Button {
                text: "Configurar mes"
                width: interface0.width * 0.5
                height: interface0.height * 0.2
                background: Rectangle {
                    color: "white"
                    radius: 20
                }
                font {
                    bold: true
                    pixelSize: 24
                }
                onClicked: {
                    console.log("Set the month")
                    interface0.visible = false
                    interface1.visible = true
                }
            }
            Button {
                text: "Configurar fondos"
                width: interface0.width * 0.5
                height: interface0.height * 0.2
                background: Rectangle {
                    color: "white"
                    radius: 20
                }
                font {
                    bold: true
                    pixelSize: 24
                }
                onClicked: {
                    console.log("Set the moneybackground")
                    interface0.visible = false
                    interface2.visible = true
                }
            }
            Button {
                text: "Introducir gastos"
                width: interface0.width * 0.5
                height: interface0.height * 0.2
                background: Rectangle {
                    color: "white"
                    radius: 20
                }
                font {
                    bold: true
                    pixelSize: 24
                }
                onClicked: {
                    console.log("Set the money expense")
                    interface0.visible = false
                    interface3.visible = true
                }
            }
        }
    }

    //INTERFACE1
    Rectangle {
        id: interface1
        width: parent.width
        height: parent.height
        visible: false
        Image {
            source: "images/image01.jpeg"
            width: parent.width
            height: parent.height
        }

        Column {
            spacing: 10
            anchors.centerIn: parent
            Rectangle {
                width: interface1.width * 0.2
                height: interface1.height * 0.2
                color: "white"
                radius: 20
                Text {
                    text: "Configurar Mes"
                    anchors.centerIn: parent
                    font {
                        bold: false
                        pixelSize: interface1.width * 0.01
                    }
                }
            }

            Row {
                spacing: 10

                ComboBox {
                    id: comboBox
                    width: interface1.width * 0.2
                    height: interface1.height * 0.2
                    background: Rectangle {
                        color: "white"
                        radius: 20
                    }
                    model: ["Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"]
                    currentIndex: 0
                    font {
                        bold: false
                        pixelSize: interface1.width * 0.01
                    }
                }

                Item {
                    width: interface1.width * 0.2
                    height: interface1.height * 0.2
                }
            }

            Row {
                spacing: 10

                Button {
                    text: "Guardar"
                    width: interface1.width * 0.2
                    height: interface1.height * 0.2
                    background: Rectangle {
                        color: "white"
                        radius: 20
                    }
                    font {
                        bold: false
                        pixelSize: interface1.width * 0.01
                    }
                    onClicked: {
                        console.log("Guardar")
                        myController.guardarComboBoxValue(comboBox.currentText)

                    }
                }
                Button {
                    text: "Principal"
                    width: interface1.width * 0.2
                    height: interface1.height * 0.2
                    background: Rectangle {
                        color: "white"
                        radius: 20
                    }
                    font {
                        bold: false
                        pixelSize: interface1.width * 0.01
                    }
                    onClicked: {
                        console.log("Principal")
                        interface0.visible = true
                        interface1.visible = false
                    }
                }
            }
        }
    }

    //INTERFACE2
    Rectangle {
        id: interface2
        width: parent.width
        height: parent.height
        visible: false

        Image {
            source: "images/image01.jpeg"
            width: parent.width
            height: parent.height
        }

        Column {
            spacing: 10 // Espacio entre las filas (puedes ajustar según tus necesidades)
            anchors.centerIn: parent // Centra la Column en la ventana
            Rectangle {
                width: interface2.width * 0.2
                height: interface2.height * 0.2
                color: "white"
                radius: 20
                Text {
                    text: "Configurar Fondos"
                    anchors.centerIn: parent
                    font {
                        bold: false
                        pixelSize: interface2.width * 0.01
                    }
                }
            }
            Row {
                spacing: 10

                ComboBox {
                    width: interface2.width * 0.2
                    height: interface2.height * 0.2
                    background: Rectangle {
                        color: "white"
                        radius: 20
                    }
                    model: ["Ahorros", "Coche", "Otros"]
                    currentIndex: 0
                    font {
                        bold: false
                        pixelSize: interface2.width * 0.01
                    }
                }

                Rectangle {
                    width: interface2.width * 0.2
                    height: interface2.height * 0.2
                    color: "white"
                    radius: 20
                    TextField {
                        placeholderText: "Dinero disponible: "
                        anchors.centerIn: parent
                        font {
                            bold: false
                            pixelSize: interface2.width * 0.01
                        }

                    }
                }
            }
            Row {
                spacing: 10

                Button {
                    text: "Guardar"
                    width: interface2.width * 0.2
                    height: interface2.height * 0.2
                    background: Rectangle {
                        color: "white"
                        radius: 20
                    }
                    font {
                        bold: false
                        pixelSize: interface2.width * 0.01
                    }
                    onClicked: {
                        console.log("Guardar")
                    }
                }
                Button {
                    text: "Principal"
                    width: interface2.width * 0.2
                    height: interface2.height * 0.2
                    background: Rectangle {
                        color: "white"
                        radius: 20
                    }
                    font {
                        bold: false
                        pixelSize: interface2.width * 0.01
                    }
                    onClicked: {
                        console.log("Principal")
                        interface0.visible = true
                        interface2.visible = false
                    }
                }
            }
        }
    }

    //INTERFACE3
    Rectangle {
        id: interface3
        width: parent.width
        height: parent.height
        visible: false

        Image {
            source: "images/image01.jpeg"
            width: parent.width
            height: parent.height
        }

        Column {
            spacing: 10 // Espacio entre las filas (puedes ajustar según tus necesidades)
            anchors.centerIn: parent // Centra la Column en la ventana
            Rectangle {
                width: interface3.width * 0.2
                height: interface3.height * 0.2
                color: "white"
                radius: 20
                Text {
                    text: "Configurar Gastos"
                    anchors.centerIn: parent
                    font {
                        bold: false
                        pixelSize: interface3.width * 0.01
                    }
                }
            }
            Row {
                spacing: 10

                ComboBox {
                    width: interface3.width * 0.2
                    height: interface3.height * 0.2
                    background: Rectangle {
                        color: "white"
                        radius: 20
                    }
                    model: ["Coche", "Otros"]
                    currentIndex: 0
                    font {
                        bold: false
                        pixelSize: interface3.width * 0.01
                    }
                }

                Rectangle {
                    width: interface3.width * 0.2
                    height: interface3.height * 0.2
                    color: "white"
                    radius: 20
                    TextField {
                        placeholderText: "Cantidad gastada: "
                        anchors.centerIn: parent
                        font {
                            bold: false
                            pixelSize: interface3.width * 0.01


                        }

                    }
                }
            }
            Row {
                spacing: 10

                Button {
                    text: "Guardar"
                    width: interface3.width * 0.2
                    height: interface3.height * 0.2
                    background: Rectangle {
                        color: "white"
                        radius: 20
                    }
                    font {
                        bold: false
                        pixelSize: interface3.width * 0.01
                    }
                    onClicked: {
                        console.log("Guardar")
                    }
                }
                Button {
                    text: "Principal"
                    width: interface3.width * 0.2
                    height: interface3.height * 0.2
                    background: Rectangle {
                        color: "white"
                        radius: 20
                    }
                    font {
                        bold: false
                        pixelSize: interface3.width * 0.01
                    }
                    onClicked: {
                        console.log("Principal")
                        interface0.visible = true
                        interface3.visible = false
                    }
                }
            }
        }
    }
}

/*
import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15  // Importa los controles básicos, incluyendo Button

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    StackView {
        id: stackView
        initialItem: "HomeForm.ui.qml"
        anchors.fill: parent
    }

    Image {
        source: "images/image01.jpeg"
        width: parent.width
        height: parent.height
    }

    Column {
        anchors.centerIn: parent
        spacing: 10
        Button {
            text: "Configurar mes"
            width: 200
            height: 100
            background: Rectangle {
                color: "white"
                radius: 20
            }
            font.bold: true
            onClicked: {
                console.log("Set the month")
                stackView.push("setMonth.qml")
            }
        }
        Button {
            text: "Configurar fondos"
            width: 200
            height: 100
            background: Rectangle {
                color: "white"
                radius: 20
            }
            font.bold: true
            onClicked: {
                console.log("Set the moneybackground")
                stackView.push("setBackgroundMoney.qml")
            }
        }
        Button {
            text: "Introducir gastos"
            width: 200
            height: 100
            background: Rectangle {
                color: "white"
                radius: 20
            }
            font.bold: true
            onClicked: {
                console.log("Set the money expense")
                stackView.push("setExpenseMoney.qml")
            }
        }
    }
}
*/

/*
import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Item {
        id: contentItem
        width: parent.width
        height: parent.height

        Rectangle {
            width: parent.width
            height: parent.height
            color: "white"

            Image {
                source: "images/image01.jpeg"
                width: parent.width
                height: parent.height
            }

            ColumnLayout {
              initialPage  anchors.centerIn: parent
                spacing: 10

                Button {
                    text: "Configurar mes"
                    width: 200
                    height: 100
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    background: Rectangle {
                        color: "white"
                        radius: 20
                    }
                    font.bold: true
                    onClicked: {
                        console.log("Set the month")
                        loadPage("setMonth.qml")
                    }
                }

                Button {
                    text: "Configurar fondos"
                    width: 200
                    height: 100
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    background: Rectangle {
                        color: "white"
                        radius: 20
                    }
                    font.bold: true
                    onClicked: {
                        console.log("Set the money background")
                        loadPage("setBackgroundMoney.qml")
                    }
                }

                Button {
                    text: "Introducir gastos"
                    width: 200
                    height: 100
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    background: Rectangle {
                        color: "white"
                        radius: 20
                    }
import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "Ejemplo de Cambio de Interfaz"

    Rectangle {
        id: root
        anchors.fill: parent

        Item {
            id: currentInterface
            anchors.fill: parent

            // Contenido de la interfaz 1
            Rectangle {
                id: interface1
                anchors.fill: parent
                visible: true

                Text {
                    text: "Interfaz 1"
                    anchors.centerIn: parent
                }

                Button {
                    text: "Cambiar a Interfaz 2"
                    anchors {
                        horizontalCenter: parent.horizontalCenter
                        top: parent.bottom
                        topMargin: 20
                    }
                    onClicked: {
                        interface1.visible = false;
                        interface2.visible = true;
                    }
                }
            }

            // Contenido de la interfaz 2
            Rectangle {
                id: interface2
                anchors.fill: parent
                visible: false

                Text {
                    text: "Interfaz 2"
                    anchors.centerIn: parent
                }

                Button {
                    text: "Cambiar a Interfaz "
                    anchors {
                        horizontalCenter: parent.horizontalCenter
                        top: parent.bottom
                        topMargin: 20
                    }
                    onClicked: {
                        interface2.visible = false;
                        interface1.visible = true;
                    }
                }
            }
        }
    }
}
                    font.bold: true
                    onClicked: {
                        console.log("Set the money expense")
                        loadPage("setExpenseMoney.qml")
                    }
                }
            }
        }
    }

    function loadPage(pageUrl) {
        var component = Qt.createComponent(pageUrl);
        if (component.status === Component.Ready) {
            var page = component.createObject(contentItem);
            if (page !== null) {
                contentItem.children = [page];
            }
        }
    }

    Component.onCompleted: {
        loadPage("initialPage.qml");
    }
}
*/

