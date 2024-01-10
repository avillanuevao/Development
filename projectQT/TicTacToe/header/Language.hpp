#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <map>
#include <string>
#include <iostream>
#include <vector>

enum Messages
{
    outOfRange,
    askNumberRows,
    askNumberColumns,
    notInteger,
    notEmptySquare,
    askCoordenateX,
    askCoordenateY, 
    rowComplete,
    columnComplete,
    diagonalComplete,
    invalidCoordinate,
    overWinner,
    overNoWinner,
    askNumberPlayers,
    invalidDimension,
    invalidNumberPlayers,
    welcomeMessage,
    askTypeGame,
    invalidTypeGame
};

enum Idioms
{
    spanish,
    english
};

class Language
{
    private:
        std::map<Idioms, std::map<Messages, std::string>> languages;
        std::map<Messages, std::string> spanish;
        std::map<Messages, std::string> english;
        Idioms selectedLanguage = Idioms::english;
        Language();

    public:
        static Language& getInstance();
        void setLanguage(Idioms idiom);
        std::string getMessage(Messages message);
        void spanishMessages();
        void englishMessages();
        std::string getIdiomName(Idioms idiom);
        std::vector<Idioms> getAvailableLanguages();
};

#endif 
