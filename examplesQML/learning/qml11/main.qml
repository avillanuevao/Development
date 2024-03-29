import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow
{
    width: 640
    height: 480
    visible: true
    title: qsTr("RowLayout//ColumnLayout")
    ColumnLayout
    {
        anchors.centerIn: parent

        RowLayout
        {
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            Button
            {
                height: parent.height
                width: parent.width / 2
                text: "TextButton"
            }

            Button
            {
                height: parent.height
                width: parent.width / 2
                text: "TextButton"
            }
        }

        RowLayout
        {
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            Button
            {
                height: parent.height
                width: parent.width / 3
                text: "TextButton"
            }

            Button
            {
                height: parent.height
                width: parent.width / 3
                text: "TextButton"
            }

            Button
            {
                height: parent.height
                width: parent.width / 3
                text: "TextButton"
            }
        }

        RowLayout
        {
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            Rectangle
            {
                height: 100
                width: 325
                color: "red"

                ColumnLayout
                {
                    anchors.centerIn: parent

                    Text
                    {
                        text: "Line 1"
                        font.pixelSize: 16
                    }
                    Text
                    {
                        text: "Line 2"
                        font.pixelSize: 16
                    }
                    Text
                    {
                        text: "Line 3"
                        font.pixelSize: 16
                    }
                }
            }
        }
    }
}
