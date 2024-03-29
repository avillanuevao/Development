import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

ColumnLayout
{
    id: columnLayout

    TextField
    {
        id: userNameTextField
        placeholderText: "User Name"

        validator: RegExpValidator{ regExp: /^[a-zA-Z0-9]+$/ }
    }

    Button
    {
        id: registerUserButton
        text: "Register"

        onClicked:
        {
            viewRegisterUser.registerUser(userNameTextField.text);
        }
    }
}
