#include "RoomDimension.h"

RoomDimension::RoomDimension(const FeetInches& len, const FeetInches& wid) : length(len), width(wid) {}

double RoomDimension::calculateArea() const {
    return FeetInches::multiply(length, width);
}
