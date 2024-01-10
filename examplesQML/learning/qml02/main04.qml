import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import Qt.labs.settings 1.0
import "jsLogic04.js" as Logic
Window {


    Settings {
        id: appSettings
        property string showButtonText: "Show"
        property string addButtonText: "Add"
        property string deleteButtonText: "Delete"
        property string saveButtonText: "Save"
        property string mbButtonText: "MoneyB"
        property string expButtonText: "Expenses"
        property string mbTextFieldV: "Add"
        property variant savingType: ["Saving", "Car", "Travel", "Rest"];
        property variant monthType: ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]
        property variant mbQuantity: [0, 0, 0, 0]
        property variant expQuantity: [0, 0, 0, 0]
        property string monthT: monthType[0]
        property int bmShowed: 0
        property int expShowed: 0
    }


    id: window
    width: Screen.width
    height: Screen.height
    visible: true
    title: qsTr("AppV3")

    Image {
        source: "images/image01.jpeg"
        width: window.width
        height: window.height
    }

    Column {
        spacing: 10
        anchors.centerIn: parent
        Row {
            spacing: 10
            Rectangle {
                id: monthItem
                width: window.width * 0.4
                height: window.height * 0.1
                Text {
                    anchors.centerIn: parent
                    text: appSettings.monthT
                    font {
                        bold: false
                        pixelSize: parent.width * 0.05
                    }
                }
            }
            Rectangle {
                id: monthChangeButtonRectangle
                width: window.width * 0.2
                height: window.height * 0.1
                Row {
                    spacing: 10
                    anchors.centerIn: parent
                    ComboBox {
                        id: monthCB
                        width: monthChangeButtonRectangle.width * 0.35
                        height: monthChangeButtonRectangle.height * 0.5
                        model: [appSettings.monthType[0], appSettings.monthType[1], appSettings.monthType[2], appSettings.monthType[3], appSettings.monthType[4], appSettings.monthType[5], appSettings.monthType[6], appSettings.monthType[7], appSettings.monthType[8], appSettings.monthType[9], appSettings.monthType[10], appSettings.monthType[11]]
                        currentIndex: 0
                        font {
                            bold: false
                            pixelSize: monthChangeButtonRectangle.width * 0.05
                        }
                    }
                    Button {
                        width: monthChangeButtonRectangle.width * 0.3
                        height: monthChangeButtonRectangle.height * 0.5
                        text: appSettings.saveButtonText
                        font {
                            bold: false
                            pixelSize: monthChangeButtonRectangle.width * 0.05
                        }
                        onClicked: {
                            Logic.modifyMonth(appSettings, monthCB.currentIndex)
                        }
                    }
                }
            }
        }


        Row {
            spacing: 10
            Item {
                id: mbItem
                width: window.width * 0.3
                height: window.height * 0.3
                Button {
                    width: mbItem.width
                    height: mbItem.height

                    background: Rectangle {
                        color: "white"
                        radius: 20
                    }

                    text: appSettings.mbButtonText
                    font {
                        bold: true
                        pixelSize: mbItem.width * 0.1
                    }

                    onClicked: {
                        mbItemExtense.visible = true
                        expItemExtense.visible = false
                    }
                }
            }

            Item {
                id: expItem
                width: window.width * 0.3
                height: window.height * 0.3

                Button {
                    width: expItem.width
                    height: expItem.height

                    background: Rectangle {
                        color: "white"
                        radius: 20
                    }

                    text: appSettings.expButtonText
                    font {
                        bold: true
                        pixelSize: expItem.width * 0.1
                    }

                    onClicked: {
                        mbItemExtense.visible = false
                        expItemExtense.visible = true
                    }
                }
            }
        }

        Item {
            id: mbItemExtense
            visible: false
            width: window.width * 0.5
            height: window.height * 0.5
            Rectangle {
                width: mbItemExtense.width
                height: mbItemExtense.height
                Row {
                    anchors.centerIn: parent
                    spacing: 10

                    ComboBox {
                        id: mbCB
                        width: mbItemExtense.width * 0.35
                        height: mbItemExtense.height * 0.35
                        model: [appSettings.savingType[0], appSettings.savingType[1], appSettings.savingType[2], appSettings.savingType[3]]
                        currentIndex: 0
                        font {
                            bold: false
                            pixelSize: mbItemExtense.width * 0.05
                        }
                    }
                    Column{
                        spacing: 10
                        Button {
                            id: bmShowButton
                            width: mbItemExtense.width * 0.35
                            height: mbItemExtense.height * 0.10
                            text: appSettings.showButtonText
                            font {
                                bold: false
                                pixelSize: parent.width * 0.1
                            }
                            onClicked: {
                                appSettings.bmShowed = appSettings.mbQuantity[mbCB.currentIndex]

                            }
                        }
                        Row {
                            spacing: 10
                            TextField {
                                id: mbTextField
                                placeholderText: appSettings.mbTextFieldV
                                width: mbItemExtense.width * 0.15
                                height: mbItemExtense.height * 0.10
                                font {
                                    bold: false
                                    pixelSize: mbItemExtense.width * 0.05
                                }
                                onTextChanged: {
                                    var inputValue = parseFloat(text);
                                    if (isNaN(inputValue)) {
                                        text = text.substring(0, text.length - 1);
                                    }
                                }
                            }
                            Button {
                                id: bmAddButton
                                width: mbItemExtense.width * 0.15
                                height: mbItemExtense.height * 0.10
                                text: appSettings.addButtonText
                                font {
                                    bold: false
                                    pixelSize: parent.width * 0.1
                                }
                            }
                        }


                        Rectangle {
                            width: mbItemExtense.width * 0.35
                            height: mbItemExtense.height * 0.10
                            color: "black"
                            Text{
                                anchors.centerIn: parent
                                text: appSettings.bmShowed
                                font {
                                    bold: false
                                    pixelSize: parent.width * 0.1
                                }
                                color: "white"
                            }
                        }
                    }
                }
            }


        }
        Item {
            id: expItemExtense
            visible: false
            width: window.width * 0.5
            height: window.height * 0.5
            Rectangle {
                width: expItemExtense.width
                height: expItemExtense.height
                Row {
                    anchors.centerIn: parent
                    spacing: 10

                    ComboBox {
                        width: expItemExtense.width * 0.35
                        height: expItemExtense.height * 0.35
                        ComboBox {
                            width: expItemExtense.width * 0.35
                            height: expItemExtense.height * 0.35
                            model: [appSettings.savingType[0], appSettings.savingType[1], appSettings.savingType[2], appSettings.savingType[3]]
                            currentIndex: 0
                            font {
                                bold: false
                                pixelSize: expItemExtense.width * 0.05
                            }
                        }
                    }
                    Column{
                        spacing: 10
                        Button {
                            id: expShowButton
                            width: expItemExtense.width * 0.35
                            height: expItemExtense.height * 0.10
                            text: appSettings.showButtonText
                            font {
                                bold: false
                                pixelSize: parent.width * 0.1
                            }
                        }
                        Button {
                            id: expAddButton
                            width: expItemExtense.width * 0.35
                            height: expItemExtense.height * 0.10
                            text: appSettings.addButtonText
                            font {
                                bold: false
                                pixelSize: parent.width * 0.1
                            }
                        }
                        Button {
                            id: expDeleteButtonText
                            width: expItemExtense.width * 0.35
                            height: expItemExtense.height * 0.10
                            text: appSettings.deleteButtonText
                            font {
                                bold: false
                                pixelSize: parent.width * 0.1
                            }
                        }
                        Rectangle {
                            width: expItemExtense.width * 0.35
                            height: expItemExtense.height * 0.10
                            color: "black"
                            Text{
                                anchors.centerIn: parent
                                text: appSettings.expShowed
                                font {
                                    bold: false
                                    pixelSize: parent.width * 0.1
                                }
                                color: "white"
                            }
                        }
                    }
                }
            }
        }
    }
}
