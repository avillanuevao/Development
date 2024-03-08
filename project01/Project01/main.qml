import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Expense Tracker")

    ColumnLayout
    {
        RowLayout
        {
            RadioButton
            {
                id: registerUserRadioButton
                text: "Register User"
                onClicked:
                {
                    registerUser.visible = true;
                    registerExpenseTracker.visible = false;
                    addExpense.visible = false;
                }
            }
            RadioButton
            {
                id: registerExpenseTrackerRadioButton
                text: "Register Expense Tracker"
                onClicked:
                {
                    registerUser.visible = false;
                    registerExpenseTracker.visible = true;
                    addExpense.visible = false;
                }
            }
            RadioButton
            {
                id: registerAddExpenseRadioButton
                text: "Add Expense"
                onClicked:
                {
                    registerUser.visible = false;
                    registerExpenseTracker.visible = false;
                    addExpense.visible = true;
                }
            }
        }

        RegisterUser
        {
            id: registerUser
            visible: false
        }

        RegisterExpenseTracker
        {
            id: registerExpenseTracker
            visible: false
        }

        AddExpense
        {
            id: addExpense
            visible: false
        }
    }
}