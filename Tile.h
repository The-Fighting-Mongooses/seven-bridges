
/*********************************************
 * Defines the interface for a Tile class.   *
 * These act as vertices for which the user  *
 * must find and itraverse a Hamiltonian     *
 * path.                                     *
 *                                           *
 * @author:       TheFightingMongooses       *
 * @version:      0.1                        *
 * @since:        2014-02-05                 *
 *                                           *
 *********************************************/
#ifndef _TILE_H_
#define _TILE_H_

#include "Location.h"

class Tile : public Location
{
  private:
    typedef Location super;
    enum State
    {
      UNUSED = 0,
      CURRENT = 1,
      USED = 2
    };

    // Has this tile been used?
    State m_traversed;

  public:
    /* CONSTRUCTORS */
    Tile();
    Tile(int x, int y);

    /* INTERFACE */
    void flip();            // Mark the tile as used.
    void make_current();    // Mark this as the players current position.
    char repr() const;      // Return a character representation of this Tile's state.
};

#endif /*_TILE_H_*/
