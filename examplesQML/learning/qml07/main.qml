import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Layout")
    color:"#ff8833"
    property  alias item3: item3
    property  alias item4: item4
    property  alias item5: item5
    property  alias item6: item6
    property  alias item7: item7
    property  alias item8: item8

    GridLayout
    {
        width: 480
        height: 250
        rowSpacing: 10
        columnSpacing: 10
        columns: 4
        rows: 4
        anchors.centerIn: parent
        Item
        {
            id: item1
            Layout.fillWidth: true
            Layout.fillHeight: true

            Layout.columnSpan: 2
            Layout.rowSpan: 1

            Button {
                anchors.centerIn: parent
                height: parent.height
                width: parent.width
                text: "Waiter"
                onClicked: {
                    buttonCreator.createButton("item3", item3.height, item3.width, "Servir") // Llama a createButton con las propiedades deseadas
                    rectangleCreator.createRectangle("item4", item4.height, item4.width) //
                    buttonCreator.createButton("item5", item5.height, item5.width, "Limpiar") // Llama a createButton con las propiedades deseadas
                    buttonCreator.createButton("item6", item6.height, item6.width, "Tomar pedidos") // Llama a createButton con las propiedades deseadas
                    buttonCreator.createButton("item7", item7.height, item7.width, "Facturar") // Llama a createButton con las propiedades deseadas
                    buttonCreator.createButton("item8", item8.height, item8.width, "Salida") // Llama a createButton con las propiedades deseadas

                }
            }
        }

        Item
        {
            id: item2
            Layout.fillWidth: true
            Layout.fillHeight: true

            Layout.columnSpan: 2
            Layout.rowSpan: 1

            Button {
                anchors.centerIn: parent
                height: parent.height
                width: parent.width
                text: "Chef"
                onClicked: {
                    buttonCreator.createButton("item3", item3.height, item3.width, "Preparar") // Llama a createButton con las propiedades deseadas
                    rectangleCreator.createRectangle("item4", item4.height, item4.width) //
                    buttonCreator.createButton("item5", item5.height, item5.width, "Cocinar") // Llama a createButton con las propiedades deseadas
                    buttonCreator.createButton("item6", item6.height, item6.width, "Organizar") // Llama a createButton con las propiedades deseadas
                    buttonCreator.createButton("item7", item7.height, item7.width, "Presentar") // Llama a createButton con las propiedades deseadas
                    buttonCreator.createButton("item8", item8.height, item8.width, "Salida") // Llama a createButton con las propiedades deseadas
                }
            }
        }


        //
        Item
        {
            id: item3
            Layout.fillWidth: true
            Layout.fillHeight: true

            Layout.columnSpan: 1
            Layout.rowSpan: 1

        }

        Item
        {
            id: item4
            Layout.fillWidth: true
            Layout.fillHeight: true

            Layout.columnSpan: 2
            Layout.rowSpan: 2
        }

        Item
        {
            id: item5
            Layout.fillWidth: true
            Layout.fillHeight: true

            Layout.columnSpan: 1
            Layout.rowSpan: 1
        }
        //

        Item
        {
            id: item6
            Layout.fillWidth: true
            Layout.fillHeight: true

            Layout.columnSpan: 1
            Layout.rowSpan: 1

        }

        Item
        {
            id: item7
            Layout.fillWidth: true
            Layout.fillHeight: true

            Layout.columnSpan: 1
            Layout.rowSpan: 1

        }

        Item
        {
            id: item8
            Layout.fillWidth: true
            Layout.fillHeight: true

            Layout.columnSpan: 4
            Layout.rowSpan: 1
        }

    }
}




