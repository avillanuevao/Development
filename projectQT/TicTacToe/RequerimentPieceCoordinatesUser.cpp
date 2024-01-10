#include "header/RequerimentPieceCoordinatesUser.hpp"

RequerimentPieceCoordinatesUser::RequerimentPieceCoordinatesUser(){}

std::pair<int, int> RequerimentPieceCoordinatesUser::getUserPieceCoordinates()
{
    Language &languageInstance = Language::getInstance();
    
    dataHandler.printMessage(languageInstance.getMessage(Messages::askCoordenateX));
    int row = dataHandler.promptInteger();

    dataHandler.printMessage(languageInstance.getMessage(Messages::askCoordenateY));
    int column = dataHandler.promptInteger();
    
    return std::pair<int, int>(row, column);
}

void RequerimentPieceCoordinatesUser::isResultExpected(std::string message){}
