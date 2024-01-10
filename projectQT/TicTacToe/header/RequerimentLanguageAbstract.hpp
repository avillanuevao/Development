#ifndef REQUERIMENTLANGUAGETESTABSTRACT_H
#define REQUERIMENTLANGUAGETESTABSTRACT_H

#include <iostream>
#include <string>
#include <vector>
#include "DataHandler.hpp"
#include "Language.hpp"

class RequerimentLanguageAbstract
{
    public:
        RequerimentLanguageAbstract(){};
        virtual int getUserLanguage() = 0;
        virtual void isExpectedResult() = 0;
};
#endif 
