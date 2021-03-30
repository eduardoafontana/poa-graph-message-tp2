#pragma once
#include <math.h>
#include <iostream>

class Distance {
public:
    template <typename t>
    static t calculateDistance(t posX1, t posY1, t posX2, t posY2);
    
};

template<typename t>
inline t Distance::calculateDistance(t posX1, t posY1, t posX2, t posY2)
{
    return std::sqrt(std::pow(posX1 - posX2, 2) + std::pow(posY1 - posY2, 2));
}
