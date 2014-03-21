#include "Obstacle.h"
#include "Location.h"

/* Initialize this Obstacle using the parent constructor. */
Obstacle::Obstacle(int x, int y) 
  : super(x, y) 
{

}

/* Return a character representation of this Obstacle. */
char Obstacle::repr() const
{
  return '#';
}

/* Pure virtual function.  Nothing to do here. */
void Obstacle::reset() 
{ 

}
