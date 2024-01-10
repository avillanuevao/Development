.pragma library

function setBackgroundMoney(settings, selectedBackgroundMoney, quantity)
{
    var quantityAsNumber = parseInt(quantity);
    switch (selectedBackgroundMoney) {
        case 0:
            settings.mbSavingVar = quantityAsNumber;
            settings.mbSavingConst = quantityAsNumber;
            break;
        case 1:
            settings.mbCarVar = quantityAsNumber;
            settings.mbCarConst = quantityAsNumber;
            break;
        case 2:
            settings.mbOtherVar = quantityAsNumber;
            settings.mbOtherConst = quantityAsNumber;
            break;
    }
}

function setExpenseMoney(settings, selectedExpenseMoney, quantity, popup)
{
    var quantityAsNumber = parseInt(quantity);
    switch(selectedExpenseMoney)
    {
        case 0:
            if(settings.mbCarVar >= quantityAsNumber){
                settings.expCarVar += quantityAsNumber;

                settings.mbCarVar -= quantityAsNumber;
            } else if(settings.mbCarVar > 0){
                settings.expCarVar += quantityAsNumber;

                var expenseS = quantityAsNumber - settings.mbCarVar;
                var expenseC = Math.abs(expenseS - quantityAsNumber);
                settings.mbCarVar -= expenseC;
                settings.mbSavingVar -= expenseS;

            } else{
                if(settings.mbSavingVar >= quantityAsNumber){
                    settings.expCarVar += quantityAsNumber;
                    settings.mbSavingVar -= quantityAsNumber;
                }
            }

            break;
        case 1:
            if(settings.mbOtherVar >= quantityAsNumber){
                settings.expOtherVar += quantityAsNumber;

                settings.mbOtherVar -= quantityAsNumber;
            } else if(settings.mbOtherVar > 0){
                settings.expOtherVar += quantityAsNumber;

                var expenseS = quantityAsNumber - settings.mbOtherVar;
                var expenseC = Math.abs(expenseS - quantityAsNumber);
                settings.mbOtherVar -= expenseC;
                settings.mbSavingVar -= expenseS;

            } else{
                if(settings.mbSavingVar >= quantityAsNumber){
                    settings.expOtherVar += quantityAsNumber;
                    settings.mbSavingVar -= quantityAsNumber;
                }
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
            settings.mbSavingVar = settings.mbSavingConst;
            break;
        case 1:
            settings.mbCarVar = settings.mbCarConst;
            break;
        case 2:
            settings.mbOtherVar = settings.mbOtherConst;
            break;
        case 3:
            settings.expCarVar = 0;
            break;
        case 4:
            settings.expOtherVar = 0;
            break;
    }
}

