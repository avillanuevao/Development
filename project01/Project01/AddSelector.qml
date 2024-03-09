import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

ColumnLayout
{
    id: columnLayout

    ListModel
    {
        id: comboBoxModel
    }

    ComboBox
    {
        id: selectExpenseTrackerComboBox
        objectName: "selectExpenseTrackerComboBox"
        model: comboBoxModel
    }

    RowLayout
    {
        id: rowLayout

        Button
        {
            id: selectAddExpenseButton
            text: "Add Expense"
            onClicked:
            {
                addExpense.visible = true;
                addUserToExpense.visible = false;
            }
        }

        Button
        {
            id: selectAddUserToExpenseButton
            text: "Add User to Expense"
            onClicked:
            {
                addExpense.visible = false;
                addUserToExpense.visible = true;
            }
        }
    }
    AddExpense
    {
        id: addExpense
        visible: false
    }

    AddUserToExpense
    {
        id: addUserToExpense
        visible: false
    }
}
