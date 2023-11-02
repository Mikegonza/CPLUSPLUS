#pragma once
#ifndef ROOMDIMENSION_H
#define ROOMDIMENSION_H

#include "FeetInches.h"

class RoomDimension {
private:
    FeetInches length;
    FeetInches width;
public:
    RoomDimension(const FeetInches& len, const FeetInches& wid);
    double calculateArea() const;
};

#endif 
