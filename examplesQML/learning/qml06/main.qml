import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Libreria")
    id: windowID

    GridLayout
    {
        anchors.centerIn: parent
        columns: 4
        rows: 3

        //Agregar
        Rectangle
        {
            id: idRectangle
            height: 100
            width: 100
            Layout.column: 0
            Layout.row: 0
            color: "#800080"
            radius: 20

            Column
            {
                spacing: 10
                anchors.centerIn: parent
                height: idRectangle.height * 0.55
                width: idRectangle.width * 0.5
                Text {
                    id: idText
                    text: qsTr("ID")
                    font.pixelSize: idRectangle * 0.1
                }


                TextField
                {
                    height: idRectangle.height * 0.5
                    width: idRectangle.width * 0.5
                    font.pixelSize: idRectangle * 0.1
                }
            }
        }

        Rectangle
        {
            height: 100
            width: 100
            Layout.column: 1
            Layout.row: 0
            color: "#800080"
            radius: 20        }

        Rectangle
        {
            height: 100
            width: 100
            Layout.column: 2
            Layout.row: 0
            color: "#800080"
            radius: 20        }

        Rectangle
        {
            height: 100
            width: 100
            Layout.column: 3
            Layout.row: 0
            color: "#800080"
            radius: 20
        }

        //Mostrar todos

        Rectangle
        {
            height: 100
            width: 200
            Layout.column: 1
            Layout.row: 1
            Layout.columnSpan: 2
            color: "#FF00FF"
            radius: 20
        }

        //Buscar por ID
        Rectangle
        {
            height: 100
            width: 200
            Layout.column: 0
            Layout.row: 2
            Layout.columnSpan: 2
            color: "#800080"
            radius: 20
        }
        Rectangle
        {
            height: 100
            width: 200
            Layout.column: 2
            Layout.row: 2
            Layout.columnSpan: 2
            color: "#800080"
            radius: 20
        }

    }
}
