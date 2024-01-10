.pragma library

function setBackgroundMoney(settings, selectedBackgroundMoney, quantity)
{
    var quantityAsNumber = parseInt(quantity);
    switch (selectedBackgroundMoney) {
        case 0:
            settings.mbSavingVar += quantityAsNumber;
            settings.savingBalanceVar = settings.mbSavingVar
            break;
        case 1:
            settings.mbCarVar += quantityAsNumber;
            settings.carBalanceVar = settings.mbCarVar
            break;
        case 2:
            settings.mbOtherVar += quantityAsNumber;
            settings.otherBalanceVar = settings.mbOtherVar
            break;
    }
}

function setExpenseMoney(settings, selectedExpenseMoney, quantity, popup)
{
    var quantityAsNumber = parseInt(quantity);
    switch(selectedExpenseMoney)
    {
        case 0:
            //fondo coche > settings.expCarVar + quantityAsNumber
            if(settings.mbCarVar >= settings.expCarVar + quantityAsNumber)
            {
                settings.expCarVar += quantityAsNumber;
                if (settings.mbCarVar >= settings.expCarVar) {
                    // Si hay suficiente dinero en el fondo de coche, resta los gastos de ahí
                    fondoCoche -= gastos;
                } else if (fondoCoche > 0) {
                    // Si el fondo de coche tiene algo de dinero pero no es suficiente, réstalo todo y resta el resto de los gastos del fondo de ahorro
                    gastos -= fondoCoche;
                    fondoCoche = 0;
                    fondoAhorro -= gastos;
                } else {
                    // Si el fondo de coche ya está vacío, resta los gastos del fondo de ahorro
                    fondoAhorro -= gastos;
                }
            }
            else{
                settings.popupVar = "No hay fondos"
                popup.open()
            }
            break;
        case 1:
            if(settings.mbOtherVar >= settings.expOtherVar + quantityAsNumber)
            {
                settings.expOtherVar += quantityAsNumber;
            }
            else{
                settings.popupVar = "No hay fondos"
                popup.open()
            }
            break;
    }
}

function setMonth(settings, selectedMonth)
{
    var month;
    switch(selectedMonth)
    {
        case 0:
            month = "Enero"
            break;
        case 1:
            month = "Febrero"
            break;
        case 2:
            month = "Marzo"
            break;
        case 3:
            month = "Abril"
            break;
        case 4:
            month = "Mayo"
            break;
        case 5:
            month = "Junio"
            break;
        case 6:
            month = "Julio"
            break;
        case 7:
            month = "Agosto"
            break;
        case 8:
            month = "Septiembre"
            break;
        case 9:
            month = "Octubre"
            break;
        case 10:
            month = "Noviembre"
            break;
        case 11:
            month = "Diciembre"
            break;
    }
    settings.monthVar = month;
}

function deleteValue(settings, index)
{
    switch(index)
    {
        case 0:
            settings.mbSavingVar = 0;
            break;
        case 1:
            settings.mbCarVar = 0;
            break;
        case 2:
            settings.mbOtherVar = 0;
            break;
        case 3:
            settings.expCarVar = 0;
            break;
        case 4:
            settings.expOtherVar = 0;
            break;
    }
}

