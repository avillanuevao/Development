#include "header/Language.hpp"

Language::Language()
{
    englishMessages();
    spanishMessages();
    
}

Language& Language::getInstance()
{
    static Language instance;
    return instance;
}

void Language::setLanguage(Idioms idiom)
{
    selectedLanguage = idiom;
}

std::string Language::getMessage(Messages message)
{
    auto diccionario = languages[selectedLanguage];
    return diccionario[message];

}

void Language::spanishMessages()
{
    spanish[Messages::welcomeMessage] = "Bienvenido al tres en raya.\n";
    spanish[Messages::askTypeGame] = "Indica la modalidad deseada:\nPulsa 0:Multijugador\nPulsa 1:Contra la maquina\n";
    spanish[Messages::invalidTypeGame] = "El tipo de modalidad indicada no es válido.";
    spanish[Messages::askNumberRows] = "Introduce el número de filas del tablero: ";
    spanish[Messages::askNumberColumns] = "Introduce el número de columnas del tablero: ";
    spanish[Messages::askCoordenateX] = "Introduce la coordenada X: ";
    spanish[Messages::askCoordenateY] = "Introduce la coordenada Y: ";
    spanish[Messages::askNumberPlayers] = "Introduce el numero de jugadores: ";
    spanish[Messages::notInteger] = "Error: Debes introducir un número entero. Intenta nuevamente.";
    spanish[Messages::notEmptySquare] = "Error: Debes introducir una celda vacía. Intenta nuevamente.";
    spanish[Messages::outOfRange] = "Error: Debes introducir un número dentro de rango. Intenta nuevamente.";
    spanish[Messages::invalidCoordinate] = "Error: Debes introducir coordenadas válidas. Intenta nuevamente.";
    spanish[Messages::invalidDimension] = "Error: Debes introducir una dimensión igual o mayor a tres. Intenta nuevamente.";
    spanish[Messages::invalidNumberPlayers] = "Error: Debes introducir numero de jugadores invalido. Intenta nuevamente.";
    spanish[Messages::rowComplete] = "Partida finalizada con vencedor en una fila";
    spanish[Messages::columnComplete] = "Partida finalizada con vencedor en una columna";
    spanish[Messages::diagonalComplete] = "Partida finalizada con vencedor en una diagonal";
    spanish[Messages::overWinner] = "Partida finalizada. Enhorabuena: ";
    spanish[Messages::overNoWinner] = "Partida finalizada en empate.";
    languages[Idioms::spanish] = spanish;
    
}

void Language::englishMessages()
{
    english[Messages::welcomeMessage] = "Welcome to Tic-Tac-Toe.\n";
    english[Messages::askTypeGame] = "Please choose your desired mode:\nPress 0:Multiplayer\nPress 1:Against machine\n";
    english[Messages::invalidTypeGame] = "The selected mode is not valid.";
    english[Messages::askNumberRows] = "Enter the number of rows on the board: ";
    english[Messages::askNumberColumns] = "Enter the number of columns on the board: ";
    english[Messages::askCoordenateX] = "Enter the X coordinate: ";
    english[Messages::askCoordenateY] = "Enter the Y coordinate: ";
    english[Messages::askNumberPlayers] = "Enter the number of players: ";
    english[Messages::notInteger] = "Error: You must enter an integer. Please try again.";
    english[Messages::notEmptySquare] = "Error: You must enter an empty cell. Please try again.";
    english[Messages::outOfRange] = "Error: You must enter a number within the range. Please try again.";
    english[Messages::invalidCoordinate] = "Error: You must enter valid coordinates. Please try again.";
    english[Messages::invalidDimension] = "Error: You must enter a dimension equal to or greater than three. Please try again.";
    english[Messages::invalidNumberPlayers] = "Error: You must enter a number of players valid. Please try again.";
    english[Messages::rowComplete] = "Game finished with a winner in a row";
    english[Messages::columnComplete] = "Game finished with a winner in a column";
    english[Messages::diagonalComplete] = "Game finished with a winner in a diagonal";
    english[Messages::overWinner] = "Game over. Congratulations: ";
    english[Messages::overNoWinner] = "Game over in a tie.";
    languages[Idioms::english] = english;
}

std::vector<Idioms> Language::getAvailableLanguages()
{
    std::vector<Idioms> languagesAvailable;
    for(std::map<Idioms,std::map<Messages, std::string>>::iterator it = languages.begin(); it != languages.end(); ++it) 
    {
        languagesAvailable.push_back(it->first);
    }
    return languagesAvailable;
}

std::string Language::getIdiomName(Idioms idiom) {
    if (idiom == Idioms::english) {
        return "English";
    } else if (idiom == Idioms::spanish) {
        return "Spanish";
    }
    // Agrega más casos para otros idiomas si es necesario
    return "Unknown";
}
