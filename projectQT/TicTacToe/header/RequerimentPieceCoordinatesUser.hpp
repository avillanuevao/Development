#ifndef REQUERIMENTPIECECOORDINATESUSER_H
#define REQUERIMENTPIECECOORDINATESUSER_H

#include "RequerimentPieceCoordinatesAbstract.hpp"

class RequerimentPieceCoordinatesUser : public RequerimentPieceCoordinatesAbstract
{
    public:
        RequerimentPieceCoordinatesUser();
        std::pair<int, int> getUserPieceCoordinates() override;
        void isResultExpected(std::string message) override;
    private:
        DataHandler dataHandler;
};
#endif 
