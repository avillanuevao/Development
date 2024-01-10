import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import Qt.labs.settings 1.0
import "jsLogic.js" as Logic

Window {

    // Crea un objeto Settings
    Settings {
        id: appSettings

        // Declara una propiedad para guardar un valor
        property string monthText: ""
        property int savingBackgroundMoneyInt: 0
        property int otherBackgroundMoneyInt: 0
        property int carBackgroundMoneyInt: 0
        property int otherExpenseMoneyInt: 0
        property int carExpenseMoneyInt: 0
    }
    //TODO: Definir en JS
    property string monthButtonText: "Set Month"
    property string expensesButtonText: "Set Expense"
    property string moneyBackgroundButtonText: "Set Moneybackground"
    property string expenseMoneyText: "Moneybackground"
    property string backgroundMoneyText: "Expenses"

    property string carExpenseMoneyText: "Car"
    property string otherExpenseMoneyText: "Others"
    property string carBackgroundMoneyText: "Car"
    property string otherBackgroundMoneyText: "Others"
    property string savingBackgroundMoneyText: "Saving"

    function setBackgroundMoney(selectedBackgroundMoney, quantity){
        Logic.setBackgroundMoney(appSettings, selectedBackgroundMoney, quantity)
    }

    function setExpenseMoney(selectedExpenseMoney, quantity){
        Logic.setExpenseMoney(appSettings, selectedExpenseMoney, quantity)
    }


    id: window
    width: Screen.width
    height: Screen.height
    visible: true
    title: qsTr("Finance app")

    //interface 1

    Rectangle {
        id: interface1
        width: window.width
        height: window.height
        visible: true
           Image {
               source: "images/image01.jpeg"
               width: interface1.width
               height: interface1.height
           }
           Row {
               id: btnInterface1
               width: interface1.width
               height: interface1.height * 0.05
               spacing: 100

               Button {
                   id: monthbutton
                   width: btnInterface1.width * 0.3
                   height: btnInterface1.height
                   text: monthButtonText
                   background: Rectangle {
                       color: "white"
                       radius: 20
                   }
                   font {
                       bold: false
                       pixelSize: monthbutton.width * 0.05
                   }
                   onClicked: {
                       //appSettings.myValue = 100;
                       console.log(appSettings.monthText)
                       interface1.visible = false
                       interface2.visible = true
                   }
               }

               Button {
                   id: expensesbutton
                   width: btnInterface1.width * 0.3
                   height: btnInterface1.height
                   text: expensesButtonText
                   background: Rectangle {
                       color: "white"
                       radius: 20
                   }
                   font {
                       bold: false
                       pixelSize: expensesbutton.width * 0.05
                   }
                   onClicked: {
                       //console.log("Valor guardado: " + appSettings.myValue);
                       interface1.visible = false
                       interface4.visible = true
                   }
               }

               Button {
                   id: moneybackgroundbutton
                   width: btnInterface1.width * 0.3
                   height: btnInterface1.height
                   text: moneyBackgroundButtonText
                   background: Rectangle {
                       color: "white"
                       radius: 20
                   }
                   font {
                       bold: false
                       pixelSize: moneybackgroundbutton.width * 0.05
                   }
                   onClicked: {
                       interface1.visible = false
                       interface3.visible = true
                   }
               }
           }

           Column {
               id: displayClm
               anchors.centerIn: parent
               spacing: 10

               Rectangle {
                   width: btnInterface1.width * 0.08
                   height: btnInterface1.height
                   color: "white"
                   radius: 20
                   Text {
                       anchors.centerIn: parent
                       text: appSettings.monthText
                       font {
                           bold: true
                           pixelSize: displayClm * 0.05
                       }
                   }
               }

               Item {
                   width: btnInterface1.width * 0.5
                   height: btnInterface1.height
                   Row {
                       anchors.centerIn: parent
                       spacing: 10
                       Rectangle {
                           width: btnInterface1.width * 0.08
                           height: btnInterface1.height
                           color: "white"
                           radius: 20
                           Text {
                               anchors.centerIn: parent
                               text: expenseMoneyText
                               font {
                                   bold: true
                                   pixelSize: displayClm * 0.05
                               }
                           }
                       }
                       Rectangle {
                           width: btnInterface1.width * 0.08
                           height: btnInterface1.height
                           color: "black"
                           radius: 20
                           Text {
                               anchors.centerIn: parent
                               text: backgroundMoneyText
                               color: "white"
                               font {
                                   bold: true
                                   pixelSize: displayClm * 0.05
                               }
                           }
                       }
                   }
               }



               Item {
                   width: btnInterface1.width * 0.5
                   height: btnInterface1.height
                   Row {
                       anchors.centerIn: parent
                       spacing: 10
                       Rectangle {
                           width: btnInterface1.width * 0.05
                           height: btnInterface1.height
                           color: "white"
                           radius: 20
                           Text {
                               anchors.centerIn: parent
                               text: savingBackgroundMoneyText
                               font {
                                   bold: true
                                   pixelSize: displayClm * 0.05
                               }
                           }
                       }
                       Rectangle {
                           width: btnInterface1.width * 0.05
                           height: btnInterface1.height
                           color: "white"
                           radius: 20
                           Text {
                               anchors.centerIn: parent
                               text: carBackgroundMoneyText
                               font {
                                   bold: true
                                   pixelSize: displayClm * 0.05
                               }
                           }
                       }
                       Rectangle {
                           width: btnInterface1.width * 0.05
                           height: btnInterface1.height
                           color: "white"
                           radius: 20
                           Text {
                               anchors.centerIn: parent
                               text: otherBackgroundMoneyText
                               font {
                                   bold: true
                                   pixelSize: displayClm * 0.05
                               }
                           }
                       }
                       Rectangle {
                           width: btnInterface1.width * 0.05
                           height: btnInterface1.height
                           color: "black"
                           radius: 20
                           Text {
                               anchors.centerIn: parent
                               text: carExpenseMoneyText
                               color: "white"
                               font {
                                   bold: true
                                   pixelSize: displayClm * 0.05
                               }
                           }
                       }
                       Rectangle {
                           width: btnInterface1.width * 0.05
                           height: btnInterface1.height
                           color: "black"
                           radius: 20
                           Text {
                               anchors.centerIn: parent
                               text: otherExpenseMoneyText
                               color: "white"
                               font {
                                   bold: true
                                   pixelSize: displayClm * 0.05
                               }
                           }
                       }
                   }
               }

               Item {
                   width: btnInterface1.width * 0.5
                   height: btnInterface1.height
                   Row {
                       anchors.centerIn: parent
                       spacing: 10
                       Rectangle {
                           width: btnInterface1.width * 0.05
                           height: btnInterface1.height
                           color: "white"
                           radius: 20
                           Text {
                               anchors.centerIn: parent
                               text: appSettings.savingBackgroundMoneyInt
                               font {
                                   bold: true
                                   pixelSize: displayClm * 0.05
                               }
                           }
                       }
                       Rectangle {
                           width: btnInterface1.width * 0.05
                           height: btnInterface1.height
                           color: "white"
                           radius: 20
                           Text {
                               anchors.centerIn: parent
                               text: appSettings.carBackgroundMoneyInt
                               font {
                                   bold: true
                                   pixelSize: displayClm * 0.05
                               }
                           }
                       }
                       Rectangle {
                           width: btnInterface1.width * 0.05
                           height: btnInterface1.height
                           color: "white"
                           radius: 20
                           Text {
                               anchors.centerIn: parent
                               text: appSettings.otherBackgroundMoneyInt
                               font {
                                   bold: true
                                   pixelSize: displayClm * 0.05
                               }
                           }
                       }
                       Rectangle {
                           width: btnInterface1.width * 0.05
                           height: btnInterface1.height
                           color: "black"
                           radius: 20
                           Text {
                               anchors.centerIn: parent
                               text: appSettings.carExpenseMoneyInt
                               color: "white"
                               font {
                                   bold: true
                                   pixelSize: displayClm * 0.05
                               }
                           }
                       }
                       Rectangle {
                           width: btnInterface1.width * 0.05
                           height: btnInterface1.height
                           color: "black"
                           radius: 20
                           Text {
                               anchors.centerIn: parent
                               text: appSettings.otherExpenseMoneyInt
                               color: "white"
                               font {
                                   bold: true
                                   pixelSize: displayClm * 0.05
                               }
                           }
                       }
                   }
               }
           }
    }

    // interface 2 - Mes
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
            spacing: 10
            anchors.centerIn: parent
            Rectangle {
                width: interface2.width * 0.2
                height: interface2.height * 0.2
                color: "white"
                radius: 20
                Text {
                    text: "Configurar Mes"
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
                    id: comboBoxMonth
                    width: interface2.width * 0.2
                    height: interface2.height * 0.2
                    background: Rectangle {
                        color: "white"
                        radius: 20
                    }
                    model: ["Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"]
                    currentIndex: 0
                    font {
                        bold: false
                        pixelSize: interface2.width * 0.01
                    }
                }

                Item {
                    width: interface2.width * 0.2
                    height: interface2.height * 0.2
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
                        var selectedMonth = comboBoxMonth.currentText
                        appSettings.monthText = selectedMonth
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
                        interface1.visible = true
                        interface2.visible = false
                    }
                }
            }
        }
    }

    // interface 3 - Ahorros
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
                    text: "Configurar Fondos"
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
                    id: comboBoxBackgroundM
                    width: interface3.width * 0.2
                    height: interface3.height * 0.2
                    background: Rectangle {
                        color: "white"
                        radius: 20
                    }
                    model: ["Ahorros", "Coche", "Otros"]
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
                        id: textFieldBackgroundM
                        placeholderText: "Dinero disponible: "
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
                        var selectedBackgroundM = comboBoxBackgroundM.currentIndex
                        var quantityBackgroundM = textFieldBackgroundM.text
                        setBackgroundMoney(selectedBackgroundM, quantityBackgroundM)
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
                        interface1.visible = true
                        interface3.visible = false
                    }
                }
            }
        }
    }

    // interface 4 - Gastos
    Rectangle {
        id: interface4
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
                width: interface4.width * 0.2
                height: interface4.height * 0.2
                color: "white"
                radius: 20
                Text {
                    text: "Configurar Gastos"
                    anchors.centerIn: parent
                    font {
                        bold: false
                        pixelSize: interface4.width * 0.01
                    }
                }
            }
            Row {
                spacing: 10

                ComboBox {
                    id: comboBoxExpenseM
                    width: interface4.width * 0.2
                    height: interface4.height * 0.2
                    background: Rectangle {
                        color: "white"
                        radius: 20
                    }
                    model: ["Coche", "Otros"]
                    currentIndex: 0
                    font {
                        bold: false
                        pixelSize: interface4.width * 0.01
                    }
                }

                Rectangle {
                    width: interface4.width * 0.2
                    height: interface4.height * 0.2
                    color: "white"
                    radius: 20
                    TextField {
                        id: textFieldExpenseM
                        placeholderText: "Cantidad gastada: "
                        anchors.centerIn: parent
                        font {
                            bold: false
                            pixelSize: interface4.width * 0.01
                        }

                    }
                }
            }
            Row {
                spacing: 10

                Button {
                    text: "Guardar"
                    width: interface4.width * 0.2
                    height: interface4.height * 0.2
                    background: Rectangle {
                        color: "white"
                        radius: 20
                    }
                    font {
                        bold: false
                        pixelSize: interface4.width * 0.01
                    }
                    onClicked: {
                        var selectedExpenseM = comboBoxExpenseM.currentIndex
                        var quantityExpenseM = textFieldExpenseM.text
                        setExpenseMoney(selectedExpenseM, quantityExpenseM)
                    }
                }
                Button {
                    text: "Principal"
                    width: interface4.width * 0.2
                    height: interface4.height * 0.2
                    background: Rectangle {
                        color: "white"
                        radius: 20
                    }
                    font {
                        bold: false
                        pixelSize: interface4.width * 0.01
                    }
                    onClicked: {
                        interface1.visible = true
                        interface4.visible = false
                    }
                }
            }
        }
    }
}
