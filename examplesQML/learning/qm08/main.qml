import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    property alias appWindow: appWindow
    property alias gridLayout: gridLayout

    id: appWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Layout")
    color:"#ff8833"

    GridLayout
    {
        id: gridLayout
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
                    itemCreator.createItem("gridLayout", 1, 1, true)
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
                }
            }
        }


        //

    }
}




