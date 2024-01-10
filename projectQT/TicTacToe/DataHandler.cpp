#include "header/DataHandler.hpp"
DataHandler::DataHandler(){}

void DataHandler::printMessage(const std::string& message)
{
    std::cout << message;
}

int DataHandler::promptInteger()
{
    Language &languageInstance = Language::getInstance();
    int integer;
    bool isInteger = true;
    do {
        if (!(std::cin >> integer)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printMessage(languageInstance.getMessage(Messages::notInteger));
            isInteger = false;
        }else{
            isInteger = true;
        }
    } while (!isInteger);
    return integer;
}