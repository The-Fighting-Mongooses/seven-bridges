#include "Obstacle.h"

Obstacle::Obstacle(int x, int y) : Location(x, y) { }

char Obstacle::repr() const
{
    return '#';
}

void Obstacle::reset() { }
