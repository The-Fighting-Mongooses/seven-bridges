/**************************************
 * Implementation for the Tile class. *
 *                                    *
 * NOTE: Do not move the include for  *
 * ANSI.h or you risk breaking the    *
 * build.  There are name resolution  *
 * conflicts with ld.gold.  This may  *
 * better anyway so the API user      *
 * doesn't have to worry about an     *
 * include that's only needed by the  *
 * API.                               *
 **************************************/

#include "Tile.h"
#include "Location.h"

/* Default constructor.  May be removed later. */
/* No need for this, and causing problems <dcp>
Tile::Tile()
{
  this->m_traversed = UNUSED;
}*/

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

void Tile::reset()
{
  this->m_traversed = UNUSED;
}
