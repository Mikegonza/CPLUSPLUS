#include "RoomCarpet.h"

RoomCarpet::RoomCarpet(int widthFeet, int widthInches, int lengthFeet, int lengthInches, double costPerSF)
    : dimensions(FeetInches(lengthFeet, lengthInches), FeetInches(widthFeet, widthInches)),
    costPerSquareFoot(costPerSF) {}

double RoomCarpet::totalCost() const {
    double area = dimensions.calculateArea();
    return area * costPerSquareFoot;
}
