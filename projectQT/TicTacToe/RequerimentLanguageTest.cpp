#include "header/RequerimentLanguageTest.hpp"

RequerimentLanguageTest::RequerimentLanguageTest(std::vector<int> languageSelected) {
    _languageSelected = languageSelected;
}

int RequerimentLanguageTest::getUserLanguage()
{
    Language &languageInstance = Language::getInstance();
    std::vector<Idioms> availableLanguages = languageInstance.getAvailableLanguages();
    bool isValidLanguage;
    Idioms selectedLanguage;
    do
    {
        if(_languageSelected[_counterGetUserLanguage] < availableLanguages.size())
        {
            selectedLanguage = availableLanguages.at(_languageSelected[_counterGetUserLanguage]);
            isValidLanguage = true;
        }else
        {
            _counterGetUserLanguage++;
            isValidLanguage = false;
        }
    } while (!isValidLanguage);
    languageInstance.setLanguage(selectedLanguage);
    return 0;
}

void RequerimentLanguageTest::isExpectedResult()
{
    Language &languageInstance = Language::getInstance();
    std::string expectedResult =  languageInstance.getMessage(Messages::askNumberRows);
    std::string spanishMessage = "Introduce el número de filas del tablero: ";
    std::string englishMessage = "Enter the number of rows on the board: ";
    if(_languageSelected[_counterGetUserLanguage] == 0)
    {
        if(expectedResult == spanishMessage)
        {
            std::cout << "Test 'RequerimentLanguageTestSpanish' passed"<< std::endl;
        }else
        {
            std::cout << "Test 'RequerimentLanguageTestSpanish' failed"<< std::endl;

        }
    }else if(_languageSelected[_counterGetUserLanguage] == 1)
    {
        if(expectedResult == englishMessage)
        {
            std::cout << "Test 'RequerimentLanguageTestEnglish' passed"<< std::endl;
        }else
        {
            std::cout << "Test 'RequerimentLanguageTestEnglish' failed"<< std::endl;

        }
    }
}
