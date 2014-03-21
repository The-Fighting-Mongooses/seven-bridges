#include "Tile.h"
#include "Location.h"

/* Typical constructor.  Creates a Tile at a user defined point. */
Tile::Tile(int x, int y)
  : super(x, y)
{
  this->m_traversed = UNUSED;
}

/* The Tile is now contained in the user's walk.  Mark it so. */
void Tile::flip() 
{
  this->m_traversed = USED;
}

/* The Tile is currently occupied by the user.  Mark it so. */
void Tile::make_current()
{
  this->m_traversed = CURRENT;
}

/* Returns a character represenation of this Tile. */;
char Tile::repr() const
{
  // Send a char back to the Display class so it can print the appropriate
  // ASCII to the screen.
  switch (this->m_traversed)
  {
    case CURRENT:
      return 'c';
    case USED:
      return 'u';
    case UNUSED:
      return 'x';
  }
}

/* Mark the tile as unused. */
void Tile::reset()
{
  this->m_traversed = UNUSED;
}
