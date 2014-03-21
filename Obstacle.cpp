#include "Obstacle.h"

Obstacle::Obstacle(int x, int y) : super(x, y) {}

char Obstacle::repr() const
{
    return '#';
}

void Obstacle::reset() { }
