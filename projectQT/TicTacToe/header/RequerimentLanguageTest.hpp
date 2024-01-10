#ifndef REQUERIMENTLANGUAGETEST_H
#define REQUERIMENTLANGUAGETEST_H

#include "RequerimentLanguageAbstract.hpp"

class RequerimentLanguageTest : public RequerimentLanguageAbstract
{
    public:
        RequerimentLanguageTest(std::vector<int> languageSelected);
        int getUserLanguage() override;
        void isExpectedResult() override;
    private:
        DataHandler dataHandler;
        std::vector<int> _languageSelected;
        int _counterGetUserLanguage = 0;
};
#endif 
