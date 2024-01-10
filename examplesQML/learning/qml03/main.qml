import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import Qt.labs.settings 1.0

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("QML03")


    Rectangle {
        id: mbContainer
        width: window.width * 0.5
        height: window.height * 0.5
        radius: 50
        anchors.centerIn: parent

        Column {
            spacing: 10
            anchors.centerIn: parent
/*Saving*/
            Row {
                spacing: 40
                Item {
                    width: mbContainer.width * 0.25
                    height: mbContainer.height * 0.15

                    Text {
                        anchors.centerIn: parent
                        text: "Saving"
                        font {
                            bold: false
                            family: "Courier New"
                            pixelSize: parent.width * 0.25
                        }
                    }
                }

                Item {
                    width: mbContainer.width * 0.25
                    height: mbContainer.height * 0.15

                    Text {
                        id: mbSavingText
                        anchors.centerIn: parent
                        text: controller.mbSaving
                        font {
                            bold: false
                            family: "Courier New"
                            pixelSize: parent.width * 0.25
                        }
                    }
                }

                Item {
                    width: mbContainer.width * 0.25
                    height: mbContainer.height * 0.15

                    Text {
                        id: expSavingText
                        anchors.centerIn: parent
                        text: controller.expSaving
                        font {
                            bold: false
                            family: "Courier New"
                            pixelSize: parent.width * 0.25
                        }
                    }
                }

                TextField {
                    id: mbSavingTextField
                    width: mbContainer.width * 0.25
                    height: mbContainer.height * 0.15
                    validator: RegExpValidator { regExp: /^-?\d*\.?\d*$/ }
                    onAccepted: {
                        controller.setMbSaving(parseFloat(mbSavingTextField.text))

                    }
                }

                TextField {
                    id: expSavingTextField
                    width: mbContainer.width * 0.25
                    height: mbContainer.height * 0.15
                    validator: RegExpValidator { regExp: /^-?\d*\.?\d*$/ }
                    onAccepted: {
                        controller.setExpSaving(parseFloat(expSavingTextField.text))
                    }
                }
            }
/*Car*/
            Row {
                spacing: 40
                Item {
                    width: mbContainer.width * 0.25
                    height: mbContainer.height * 0.15

                    Text {
                        anchors.centerIn: parent
                        text: "Car"
                        font {
                            bold: false
                            family: "Courier New"
                            pixelSize: parent.width * 0.25
                        }
                    }
                }

                Item {
                    width: mbContainer.width * 0.25
                    height: mbContainer.height * 0.15

                    Text {
                        id: mbCarText
                        anchors.centerIn: parent
                        text: controller.mbCar
                        font {
                            bold: false
                            family: "Courier New"
                            pixelSize: parent.width * 0.25
                        }
                    }
                }

                Item {
                    width: mbContainer.width * 0.25
                    height: mbContainer.height * 0.15

                    Text {
                        id: expCarText
                        anchors.centerIn: parent
                        text: controller.expCar
                        font {
                            bold: false
                            family: "Courier New"
                            pixelSize: parent.width * 0.25
                        }
                    }
                }

                TextField {
                    id: mbCarTextField
                    width: mbContainer.width * 0.25
                    height: mbContainer.height * 0.15
                    validator: RegExpValidator { regExp: /^-?\d*\.?\d*$/ }
                    onAccepted: {
                        controller.setMbCar(parseFloat(mbCarTextField.text))
                    }
                }

                TextField {
                    id: expCarTextField
                    width: mbContainer.width * 0.25
                    height: mbContainer.height * 0.15
                    validator: RegExpValidator { regExp: /^-?\d*\.?\d*$/ }
                    onAccepted: {
                        controller.setExpCar(parseFloat(expCarTextField.text))

                    }
                }
            }
/*Travel*/
            Row {
                spacing: 40
                Item {
                    width: mbContainer.width * 0.25
                    height: mbContainer.height * 0.15

                    Text {
                        anchors.centerIn: parent
                        text: "Travel"
                        font {
                            bold: false
                            family: "Courier New"
                            pixelSize: parent.width * 0.25
                        }
                    }
                }

                Item {
                    width: mbContainer.width * 0.25
                    height: mbContainer.height * 0.15

                    Text {
                        id: mbTravelText
                        anchors.centerIn: parent
                        text: controller.mbTravel
                        font {
                            bold: false
                            family: "Courier New"
                            pixelSize: parent.width * 0.25
                        }
                    }
                }

                Item {
                    width: mbContainer.width * 0.25
                    height: mbContainer.height * 0.15

                    Text {
                        id: expTravelText
                        anchors.centerIn: parent
                        text: controller.expTravel
                        font {
                            bold: false
                            family: "Courier New"
                            pixelSize: parent.width * 0.25
                        }
                    }
                }

                TextField {
                    id: mbTravelTextField
                    width: mbContainer.width * 0.25
                    height: mbContainer.height * 0.15
                    validator: RegExpValidator { regExp: /^-?\d*\.?\d*$/ }
                    onAccepted: {
                        controller.setMbTravel(parseFloat(mbTravelTextField.text))
                    }
                }

                TextField {
                    id: expTravelTextField
                    width: mbContainer.width * 0.25
                    height: mbContainer.height * 0.15
                    validator: RegExpValidator { regExp: /^-?\d*\.?\d*$/ }
                    onAccepted: {
                        controller.setExpTravel(parseFloat(expTravelTextField.text))
                    }
                }
            }
/*Rest*/
            Row {
                spacing: 40
                Item {
                    width: mbContainer.width * 0.25
                    height: mbContainer.height * 0.15

                    Text {
                        anchors.centerIn: parent
                        text: "Rest"
                        font {
                            bold: false
                            family: "Courier New"
                            pixelSize: parent.width * 0.25
                        }
                    }
                }

                Item {
                    width: mbContainer.width * 0.25
                    height: mbContainer.height * 0.15

                    Text {
                        id: mbRestText
                        anchors.centerIn: parent
                        text: controller.mbRest
                        font {
                            bold: false
                            family: "Courier New"
                            pixelSize: parent.width * 0.25
                        }
                    }
                }

                Item {
                    width: mbContainer.width * 0.25
                    height: mbContainer.height * 0.15

                    Text {
                        id: expRestText
                        anchors.centerIn: parent
                        text: controller.expRest
                        font {
                            bold: false
                            family: "Courier New"
                            pixelSize: parent.width * 0.25
                        }
                    }
                }

                TextField {
                    id: mbRestTextField
                    width: mbContainer.width * 0.25
                    height: mbContainer.height * 0.15
                    validator: RegExpValidator { regExp: /^-?\d*\.?\d*$/ }
                    onAccepted: {
                        controller.setMbRest(parseFloat(mbRestTextField.text))
                    }
                }

                TextField {
                    id: expRestTextField
                    width: mbContainer.width * 0.25
                    height: mbContainer.height * 0.15
                    validator: RegExpValidator { regExp: /^-?\d*\.?\d*$/ }
                    onAccepted: {
                        controller.setExpRest(parseFloat(expRestTextField.text))
                    }
                }
            }
        }
    }
}
