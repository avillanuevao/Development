#include "header/RequerimentLanguageUser.hpp"

RequerimentLanguageUser::RequerimentLanguageUser() {}

int RequerimentLanguageUser::getUserLanguage()
{
    Language &languageInstance = Language::getInstance();
    std::string languageOption;
    std::string message;

    message = "Desired language: \n";
    dataHandler.printMessage(message);

    std::vector<Idioms> availableLanguages = languageInstance.getAvailableLanguages();
    for(int i = 0; i < availableLanguages.size(); i++)
    {
        switch (availableLanguages[i])
        {
        case 0:
            /* code */
            languageOption = "Spanish";
            break;
        case 1:
            /* code */
            languageOption = "English";
            break;
        default:
            break;
        }
        message = "Press " + std::to_string(i) + ":" + languageOption + "\n";
        dataHandler.printMessage(message);
    }

    int selectedLanguageNumber;
    bool isValidLanguage;
    Idioms selectedLanguage;
    do
    {
        selectedLanguageNumber = dataHandler.promptInteger();
        std::vector<Idioms> availableLanguages = languageInstance.getAvailableLanguages();
        if(selectedLanguageNumber < availableLanguages.size())
        {
            selectedLanguage = availableLanguages.at(selectedLanguageNumber);
            isValidLanguage = true;
        }else
        {
            message = "Language not found. Try again!\n";
            dataHandler.printMessage(message);
            isValidLanguage = false;
        }
    } while (!isValidLanguage);
    
    languageInstance.setLanguage(selectedLanguage);
    return 0;
}

void RequerimentLanguageUser::isExpectedResult(){}
