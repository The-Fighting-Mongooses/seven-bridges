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
#include "ANSI.h"

/* Default constructor.  May be removed later. */
Tile::Tile()
{
  super();
  this->m_traversed = UNUSED;
}

/* Typical constructor.  Creates a Tile at a user defined point. */
Tile::Tile(int x, int y)
{
  super(x, y);
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

/* Returns a string represenation of this Tile. */;
string Tile::repr() const
{
  string representation = "";

  switch (this->m_traversed)
  {
    case UNUSED:
    default:
      representation += ANSI::blue_bg;
      break;

    case CURRENT:
      representation += ANSI::yellow_bg;
      break;

    case USED:
      representation += ANSI::red_bg;
      break;
  }

  representation += " " + ANSI::normal;
  return representation;
}

