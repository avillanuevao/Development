import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Layouts 1.15

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("QML form C++")

    property alias columnLayout: columnLayout // Hace disponible el ColumnLayout para acceso desde C++
    property alias rowLayout: rowLayout // Hace disponible el ColumnLayout para acceso desde C++

    ColumnLayout
    {
        id: columnLayout
        anchors.centerIn: parent
        RowLayout
        {
            id: rowLayout
        }
    }
}
