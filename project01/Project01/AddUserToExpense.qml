import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

ColumnLayout
{
    id: columnLayout

    ComboBox
    {
        id: selectUserAvailableComboBox
        objectName: "selectUserAvailableComboBox"
    }

    Button
    {
        id: registerNewUserToExpenseButton
        text: "Register"

        onClicked:
        {

        }
    }
}
