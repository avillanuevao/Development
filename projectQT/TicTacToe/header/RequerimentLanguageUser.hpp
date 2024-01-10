#ifndef REQUERIMENTLANGUAGEUSER_H
#define REQUERIMENTLANGUAGEUSER_H

#include "RequerimentLanguageAbstract.hpp"

class RequerimentLanguageUser : public RequerimentLanguageAbstract
{
    public:
        RequerimentLanguageUser();
        int getUserLanguage() override;
        void isExpectedResult() override;
    private:
        DataHandler dataHandler;
};
#endif 
