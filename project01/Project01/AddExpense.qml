import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

ColumnLayout
{
    id: columnLayout

    RowLayout
    {
        id: rowLayout

        ComboBox
        {
            id: selectUserComboBox
            objectName: "selectUserComboBox"
        }
    }


    TextField
    {
        id: expenseTextField
        placeholderText: "Expense"

        validator: RegExpValidator{ regExp: /^\d+$/ }
    }


    Button
    {
        id: registerExpense
        text: "Register Expense"

        onClicked:
        {

        }
    }
}
