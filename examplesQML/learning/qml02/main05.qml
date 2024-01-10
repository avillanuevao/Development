import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import Qt.labs.settings 1.0
Window {
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
                    text: myController.monthType[0]
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
                        model: [myController.monthType[0], myController.monthType[1], myController.monthType[2], myController.monthType[3], myController.monthType[4], myController.monthType[5], myController.monthType[6], myController.monthType[7], myController.monthType[8], myController.monthType[9], myController.monthType[10], myController.monthType[11]]
                        currentIndex: 0
                        font {
                            bold: false
                            pixelSize: monthChangeButtonRectangle.width * 0.05
                        }
                    }
                    Button {
                        width: monthChangeButtonRectangle.width * 0.3
                        height: monthChangeButtonRectangle.height * 0.5
                        text: myController.saveButtonText
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

                    text: myController.mbButtonText
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

                    text: myController.expButtonText
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
                        model: [myController.savingType[0], myController.savingType[1], myController.savingType[2], myController.savingType[3]]
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
                            text: myController.showButtonText
                            font {
                                bold: false
                                pixelSize: parent.width * 0.1
                            }
                            onClicked: {
                                bmShowed = myController.mbQuantity[mbCB.currentIndex]
                            }
                        }
                        Row {
                            spacing: 10
                            TextField {
                                id: mbTextField
                                placeholderText: myController.mbTextFieldV
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
                                text: myController.addButtonText
                                font {
                                    bold: false
                                    pixelSize: parent.width * 0.1
                                }
                                onClicked: {
                                    myController.updateMbQuantity(mbCB.currentIndex, parseFloat(mbTextField.text))
                                }
                            }
                        }


                        Rectangle {
                            width: mbItemExtense.width * 0.35
                            height: mbItemExtense.height * 0.10
                            color: "black"
                            Text{
                                anchors.centerIn: parent
                                text: myController.bmShowed
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
                        id: expCB
                        width: expItemExtense.width * 0.35
                        height: expItemExtense.height * 0.35
                        model: [myController.savingType[0], myController.savingType[1], myController.savingType[2], myController.savingType[3]]
                        currentIndex: 0
                        font {
                            bold: false
                            pixelSize: expItemExtense.width * 0.05
                        }
                    }

                    Column{
                        spacing: 10
                        Button {
                            id: expShowButton
                            width: expItemExtense.width * 0.35
                            height: expItemExtense.height * 0.10
                            text: myController.showButtonText
                            font {
                                bold: false
                                pixelSize: parent.width * 0.1
                            }
                        }

                        Row {
                            spacing: 10

                            TextField {
                                id: expTextField
                                placeholderText: myController.mbTextFieldV
                                width: expItemExtense.width * 0.15
                                height: expItemExtense.height * 0.10
                                font {
                                    bold: false
                                    pixelSize: expItemExtense.width * 0.05
                                }
                                onTextChanged: {
                                    var inputValue = parseFloat(text);
                                    if (isNaN(inputValue)) {
                                        text = text.substring(0, text.length - 1);
                                    }
                                }
                            }

                            Button {
                                id: expAddButton
                                width: expItemExtense.width * 0.35
                                height: expItemExtense.height * 0.10
                                text: myController.addButtonText
                                font {
                                    bold: false
                                    pixelSize: parent.width * 0.1
                                }
                                onClicked: {
                                    myController.updateExpQuantity(expCB.currentIndex, parseFloat(expTextField.text))
                                }
                            }
                        }


                        Button {
                            id: expDeleteButtonText
                            width: expItemExtense.width * 0.35
                            height: expItemExtense.height * 0.10
                            text: myController.deleteButtonText
                            font {
                                bold: false
                                pixelSize: parent.width * 0.1
                            }
                            onClicked: {
                                myController.updateExpQuantity(expCB.currentIndex, (myController.expQuantity[expCB.currentIndex])*-1)
                            }
                        }

                        Rectangle {
                            width: expItemExtense.width * 0.35
                            height: expItemExtense.height * 0.10
                            color: "black"
                            Text{
                                anchors.centerIn: parent
                                text: myController.expShowed
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
