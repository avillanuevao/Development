import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    visible: true
    width: 300
    height: 200
    title: "Creación dinámica"

    Rectangle {
        anchors.centerIn: parent
        width: parent.width * 0.5
        height: parent.height * 0.5
        color: "red"
        Text {
            id: text
            text: qsTr("text")
        }
    }

    property  alias columnLayoutA: columnLayoutA
    property  alias rowLayoutA: rowLayoutA
    property  alias rowLayoutB: rowLayoutB
    property  alias rowLayoutC: rowLayoutC
    property  alias rowLayoutD: rowLayoutD

    ColumnLayout {
        id: columnLayoutA
        anchors.centerIn: parent
        spacing: 50
        RowLayout
        {
            id: rowLayoutA
        }

        RowLayout
        {
            id: rowLayoutB
        }

        RowLayout
        {
            id: rowLayoutC
        }

        RowLayout
        {
            id: rowLayoutD
        }
    }
}
