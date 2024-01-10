import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import Qt.labs.settings 1.0
import "jsLogic.js" as Logic

Window {
    id: window
    width: Screen.width
    height: Screen.height
    visible: true
    title: qsTr("AppV2")

    Settings {
        id: appSettings

        // Declara una propiedad para guardar un valor
        property string popupVar: "Sin fondos"

        property string monthLabelVar: "Mes"
        property string monthVar: ""
        property string mbLabelVar: "Ahorros"
        property string expensesLabelVar: "Gastos"
        property string mbSavingLabelVar: "Ahorros"
        property int mbSavingVar: 0
        property string mbCarLabelVar: "Coche"
        property int mbCarVar: 0
        property string mbOtherLabelVar: "Otros"
        property int mbOtherVar: 0
        property string expCarLabelVar: "Coche"
        property int expCarVar: 0
        property string expOtherLabelVar: "Otros"
        property int expOtherVar: 0
        property string mbTextFieldVar: "Dinero disponible.."
        property string expTextFieldVar: "Dinero gastado.."
        property string saveButton: "Guardar"

        property string savingBalanceVar: "0"
        property string carBalanceVar: "0"
        property string otherBalanceVar: "0"
    }



    Image {
        source: "images/image01.jpeg"
        width: window.width
        height: window.height
    }

    Popup {
        id: popup
        width: parent.width * 0.8
        height: parent.height * 0.4
        anchors.centerIn: parent
        modal: true

        contentItem: Rectangle {
            width: parent.width
            height: parent.height
            color: "lightblue"

            Text {
                text: popupVar
                anchors.centerIn: parent
            }

            Button {
                text: "Cerrar"
                anchors.bottom: parent.bottom
                anchors.horizontalCenter: parent.horizontalCenter

                onClicked: {
                    popup.close()
                }
            }
        }
    }
    //

    Column {
        id: dataClm
        anchors.centerIn: parent
        spacing: 50

        Rectangle {
            id: monthHeaderRectangle
            width: window.width * 0.25
            height: window.height * 0.15
            radius: 20
            Column {
                anchors.centerIn: monthHeaderRectangle
                spacing: 10
                Text {
                    id: monthLabel
                    anchors.centerIn: monthHeaderRectangle
                    text: appSettings.monthLabelVar
                    font.pixelSize: monthHeaderRectangle.width * 0.1
                }
                Text {
                    id: month
                    anchors.centerIn: monthHeaderRectangle
                    text: appSettings.monthVar
                    font.pixelSize: monthHeaderRectangle.width * 0.1
                }
            }
        }

        Item {
            width: window.width * 0.25
            height: window.height * 0.15

            Row {
                anchors.centerIn: parent
                spacing: 30
                Rectangle {
                    id: mbHeaderRectangle
                    width: window.width * 0.15
                    height: window.height * 0.15
                    radius: 20
                    Text {
                        id: mbLabel
                        anchors.centerIn: mbHeaderRectangle
                        text: appSettings.mbLabelVar
                        font.pixelSize: mbHeaderRectangle.width * 0.1
                    }
                }
                Rectangle {
                    id: expHeaderRectangle
                    width: window.width * 0.15
                    height: window.height * 0.15
                    radius: 20
                    color: "black"
                    Text {
                        id: expensesLabel
                        anchors.centerIn: expHeaderRectangle
                        text: appSettings.expensesLabelVar
                        color: "white"
                        font.pixelSize: expHeaderRectangle.width * 0.1
                    }
                }
            }
        }
        Item {
            width: window.width * 0.25
            height: window.height * 0.15

            Row {
                anchors.centerIn: parent
                spacing: 30
                Rectangle {
                    id: mbSavingRectangle
                    width: window.width * 0.15
                    height: window.height * 0.15
                    radius: 20
                    Column {
                        anchors.centerIn: mbSavingRectangle
                        spacing: 5
                        Text {
                            id: mbSavingLabel
                            anchors.centerIn: mbSavingRectangle
                            text: appSettings.mbSavingLabelVar
                            font.pixelSize: mbSavingRectangle.width * 0.1
                        }
                        Text {
                            id: mbSaving
                            anchors.centerIn: mbSavingRectangle
                            text: appSettings.mbSavingVar
                            font.pixelSize: mbSavingRectangle.width * 0.1
                        }
                    }
                }
                Rectangle {
                    id: mbCarRectangle
                    width: window.width * 0.15
                    height: window.height * 0.15
                    radius: 20
                    Column {
                        anchors.centerIn: mbCarRectangle
                        spacing: 5
                        Text {
                            id: mbCarLabel
                            anchors.centerIn: mbCarRectangle
                            text: appSettings.mbCarLabelVar
                            font.pixelSize: mbCarRectangle.width * 0.1
                        }
                        Text {
                            id: mbCar
                            anchors.centerIn: mbCarRectangle
                            text: appSettings.mbCarVar
                            font.pixelSize: mbCarRectangle.width * 0.1
                        }
                    }
                }
                Rectangle {
                    id: mbOtherRectangle
                    width: window.width * 0.15
                    height: window.height * 0.15
                    radius: 20
                    Column {
                        anchors.centerIn: mbOtherRectangle
                        spacing: 5
                        Text {
                            id: mbOtherLabel
                            anchors.centerIn: mbOtherRectangle
                            text: appSettings.mbOtherLabelVar
                            font.pixelSize: mbOtherRectangle.width * 0.1
                        }
                        Text {
                            id: mbOther
                            anchors.centerIn: mbOtherRectangle
                            text: appSettings.mbOtherVar
                            font.pixelSize: mbOtherRectangle.width * 0.1
                        }
                    }
                }
                Rectangle {
                    id: expCarRectangle
                    width: window.width * 0.15
                    height: window.height * 0.15
                    radius: 20
                    color: "black"
                    Column {
                        anchors.centerIn: expCarRectangle
                        spacing: 5
                        Text {
                            id: expCarLabel
                            anchors.centerIn: expCarRectangle
                            text: appSettings.expCarLabelVar
                            color: "white"
                            font.pixelSize: expCarRectangle.width * 0.1
                        }
                        Text {
                            id: expCar
                            anchors.centerIn: expCarRectangle
                            text: appSettings.expCarVar
                            color: "white"
                            font.pixelSize: expCarRectangle.width * 0.1
                        }
                    }
                }
                Rectangle {
                    id: expOtherRectangle
                    width: window.width * 0.15
                    height: window.height * 0.15
                    radius: 20
                    color: "black"
                    Column {
                        anchors.centerIn: expOtherRectangle
                        spacing: 5
                        Text {
                            id: expOtherLabel
                            anchors.centerIn: expOtherRectangle
                            text: appSettings.expOtherLabelVar
                            color: "white"
                            font.pixelSize: expOtherRectangle.width * 0.1
                        }
                        Text {
                            id: expOther
                            anchors.centerIn: expOtherRectangle
                            text: appSettings.expOtherVar
                            color: "white"
                            font.pixelSize: expOtherRectangle.width * 0.1
                        }
                    }
                }
            }
        }

        Item {
            width: window.width * 0.25
            height: window.height * 0.35

            Row {
                anchors.centerIn: parent
                spacing: 10

                Rectangle {
                    id: setMBRectangle
                    width: window.width * 0.15
                    height: window.height * 0.25
                    radius: 20
                    Column {
                        id: setMBColumn
                        anchors.centerIn: setMBRectangle
                        spacing: 5
                        ComboBox {
                            id: mbComboBox
                            width: setMBRectangle.width
                            height: setMBRectangle.height * 0.3
                            background: Rectangle {
                                color: "white"
                                radius: 20
                            }
                            model: ["Ahorros", "Coche", "Otros"]
                            currentIndex: 0
                            font {
                                bold: false
                                pixelSize: setMBRectangle.width * 0.1
                            }
                        }

                        TextField {
                            id: mbTextField
                            placeholderText: appSettings.mbTextFieldVar
                            font {
                                bold: false
                                pixelSize: setExRectangle.width * 0.1
                            }
                            onTextChanged: {
                                // Verifica si el texto ingresado es un número
                                var inputValue = parseFloat(text);
                                if (isNaN(inputValue)) {
                                    // Si no es un número, borra el último carácter
                                    text = text.substring(0, text.length - 1);
                                }
                            }
                        }

                        Button {
                            id: mbButton
                            width: setMBRectangle.width * 0.3
                            height: setMBRectangle.height * 0.3
                            text: appSettings.saveButton
                            background: Rectangle {
                                color: "grey"
                                radius: 20
                            }
                            font {
                                bold: false
                                pixelSize: setResetRectangle.width * 0.05
                            }
                            onClicked: {
                                console.log("mbButtonClicked")
                                var selectedBackgroundM = mbComboBox.currentIndex
                                var quantityBackgroundM = mbTextField.text
                                Logic.setBackgroundMoney(appSettings, selectedBackgroundM, quantityBackgroundM)
                            }
                        }
                    }
                }

                Rectangle {
                    id: setExRectangle
                    width: window.width * 0.15
                    height: window.height * 0.25
                    radius: 20
                    Column {
                        id: setExColumn
                        anchors.centerIn: setExRectangle
                        spacing: 5
                        ComboBox {
                            id: expComboBox
                            width: setExRectangle.width
                            height: setExRectangle.height * 0.3
                            background: Rectangle {
                                color: "white"
                                radius: 20
                            }
                            model: ["Coche", "Otros"]
                            currentIndex: 0
                            font {
                                bold: false
                                pixelSize: setExRectangle.width * 0.1
                            }
                        }

                        TextField {
                            id: expTextField
                            placeholderText: appSettings.expTextFieldVar

                            font {
                                bold: false
                                pixelSize: setExRectangle.width * 0.1
                            }
                            onTextChanged: {
                                // Verifica si el texto ingresado es un número
                                var inputValue = parseFloat(text);
                                if (isNaN(inputValue)) {
                                    // Si no es un número, borra el último carácter
                                    text = text.substring(0, text.length - 1);
                                }
                            }
                        }
                        Button {
                            id: expButton
                            width: setExRectangle.width * 0.3
                            height: setExRectangle.height * 0.3
                            text: appSettings.saveButton
                            background: Rectangle {
                                color: "grey"
                                radius: 20
                            }
                            font {
                                bold: false
                                pixelSize: setResetRectangle.width * 0.05
                            }
                            onClicked: {
                                console.log("expButtonClicked")
                                var selectedExpenseM = expComboBox.currentIndex
                                var quantityExpenseM = expTextField.text
                                Logic.setExpenseMoney(appSettings, selectedExpenseM, quantityExpenseM, popup)

                            }
                        }
                    }
                }

                Rectangle {
                    id: setMonthRectangle
                    width: window.width * 0.15
                    height: window.height * 0.25
                    radius: 20
                    Column {
                        id: setMonthColumn
                        anchors.centerIn: setMonthRectangle
                        spacing: 50
                        ComboBox {
                            id: monthComboBox
                            width: setMonthRectangle.width
                            height: setMonthRectangle.height * 0.3
                            background: Rectangle {
                                color: "white"
                                radius: 20
                            }
                            model: ["Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"]
                            currentIndex: 0
                            font {
                                bold: false
                                pixelSize: setMonthRectangle.width * 0.1
                            }
                        }
                        Button {
                            id: monthButton
                            width: setMonthRectangle.width * 0.3
                            height: setMonthRectangle.height * 0.3
                            text: appSettings.saveButton
                            background: Rectangle {
                                color: "grey"
                                radius: 20
                            }
                            font {
                                bold: false
                                pixelSize: setResetRectangle.width * 0.05
                            }
                            onClicked: {
                                console.log("monthButtonClicked")
                                var selectedMonth = monthComboBox.currentIndex
                                Logic.setMonth(appSettings, selectedMonth)

                            }
                        }
                    }
                }

                Rectangle {
                    id: setResetRectangle
                    width: window.width * 0.15
                    height: window.height * 0.35
                    radius: 20
                    Column {
                        id: setResetColumn
                        anchors.centerIn: setResetRectangle
                        spacing: 0
                        Rectangle {
                            width: setResetRectangle.width
                            height: setResetRectangle.height * 0.8
                            ListView {
                                id: deleteList
                                width: parent.width
                                height: parent.height
                                model: ListModel {
                                    ListElement { text: "Ahorros"; checked: false }
                                    ListElement { text: "Fondos coche"; checked: false }
                                    ListElement { text: "Fondos resto"; checked: false }
                                    ListElement { text: "Gastos coche"; checked: false }
                                    ListElement { text: "Gastos resto"; checked: false }
                                }
                                delegate: CheckDelegate {
                                    text: model.text
                                    checked: model.checked
                                    onCheckedChanged: model.checked = checked
                                    font.pixelSize: setResetRectangle.width * 0.1
                                }

                            }
                        }
                        Button {
                            id: deleteButton
                            width: setResetRectangle.width * 0.3
                            height: setResetRectangle.height * 0.1
                            text: appSettings.saveButton
                            background: Rectangle {
                                color: "grey"
                                radius: 20
                            }
                            font {
                                bold: false
                                pixelSize: setResetRectangle.width * 0.05
                            }
                            onClicked: {
                                console.log("deleteButtonClicked")
                                for (var i = 0; i < deleteList.model.count; i++) {
                                    if (deleteList.model.get(i).checked) {
                                        Logic.deleteValue(appSettings, i);
                                    }
                                }
                            }
                        }
                    }
                }
                Rectangle {
                    id: getBalanceRectangle
                    width: window.width * 0.15
                    height: window.height * 0.25
                    radius: 20
                    Column {
                        id: getBalanceColumn
                        anchors.centerIn: getBalanceRectangle
                        spacing: 5

                        Text {
                            id: balanceSavingTextField
                            text: "Ahorros: " + appSettings.savingBalanceVar
                            font {
                                bold: false
                                pixelSize: getBalanceRectangle.width * 0.1
                            }
                        }
                        Text {
                            id: balanceCarTextField
                            text: "Coche: " + appSettings.carBalanceVar
                            font {
                                bold: false
                                pixelSize: getBalanceRectangle.width * 0.1
                            }
                        }
                        Text {
                            id: balanceOtherTextField
                            text: "Otros: " + appSettings.otherBalanceVar
                            font {
                                bold: false
                                pixelSize: getBalanceRectangle.width * 0.1
                            }
                        }
                    }
                }
            }
        }
    }
}
