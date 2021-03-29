#include "Distance.h"

double Distance::calculateDistance(double posX1, double posY1, double posX2, double posY2)
{
    /// <summary>
    /// calculate the eucledian distance between 2 points
    /// </summary>
    /// <param name="posX1">pos of x1 in the graph</param>
    /// <param name="posY1">pos of y1 in the graph</param>
    /// <param name="posX2">pos of x2 in the graph</param>
    /// <param name="posY2">pos of y2 in the graph</param>
    /// <returns>return the distance between the 2 points</returns>
    return std::sqrt(std::pow(posX1 - posX2, 2) + std::pow(posY1 - posY2, 2));
}
