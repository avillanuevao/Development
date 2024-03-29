import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    property alias principalColumn: principalColumn
    property alias appW: appW

    width: 640
    height: 480
    visible: true
    title: qsTr("SceneA")
    id: appW

    ColumnLayout
    {
        objectName: "principal"
        id: principalColumn
        anchors.centerIn: parent
    }
}
