#pragma once
#ifndef ROOMCARPET_H
#define ROOMCARPET_H

#include "RoomDimension.h"

class RoomCarpet {
private:
    RoomDimension dimensions;
    double costPerSquareFoot;
public:
    RoomCarpet(int widthFeet, int widthInches, int lengthFeet, int lengthInches, double costPerSF);
    double totalCost() const;
};

#endif 
