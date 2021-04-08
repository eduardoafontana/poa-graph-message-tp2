#pragma once
#include <math.h>
#include <iostream>

class Distance {
/// <summary>
/// Utilitary class that serves to calculate the distance between two points
/// </summary>
public:
    template<typename t>
    static t calculateDistance(t posX1, t posY1, t posX2, t posY2);
    
};

template<typename t>
inline t Distance::calculateDistance(t posX1, t posY1, t posX2, t posY2)
{
    /// <summary>
    /// calculate the distance between two points
    /// </summary>
    /// <typeparam name="t"></typeparam>
    /// <param name="posX1"></param>
    /// <param name="posY1"></param>
    /// <param name="posX2"></param>
    /// <param name="posY2"></param>
    /// <returns>the distance between the points</returns>
    return std::sqrt(std::pow(posX1 - posX2, 2) + std::pow(posY1 - posY2, 2));
}
