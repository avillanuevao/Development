#include "PrintOptionDisplay.hpp"

PrintOptionDisplay::PrintOptionDisplay()
{

}

void PrintOptionDisplay::printOptionDisplay()
{
    QString displayText = "Seleccione Acción:\n"
                              "0.Añadir Fondo Ahorro 9.Añadir Gasto Ahorro\n"
                              "1.Añadir Fondo Hogar 10.Añadir Gasto Hogar\n"
                              "2.Añadir Fondo Comida 11.Añadir Gasto Comida\n"
                              "3.Añadir Fondo Transporte 12.Añadir Gasto Transporte\n"
                              "4.Añadir Fondo Entretenimiento 13.Añadir Gasto  Entretenimiento\n"
                              "5.Añadir Fondo Viaje 14.Añadir Gasto Viaje\n"
                              "6.Añadir Fondo Ropa 15.Añadir Gasto Ropa\n"
                              "7.Añadir Fondo Deuda 16.Añadir Gasto Deuda\n"
                              "8.Añadir Fondo Coche 17.Añadir Gasto Coche\n"
                              "18.Salir\n";
    std::cout << displayText.toStdString() << std::endl;
}
