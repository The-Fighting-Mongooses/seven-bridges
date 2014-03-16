
/*********************************************
 * Defines the interface for a Tile class.   *
 * These act as vertices for which the user  *
 * must find and itraverse a Hamiltonian     *
 * path.                                     *
 *                                           *
 * @author:       William Hollingsworth      *
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

    State m_traversed;

  public:
    /* CONSTRUCTORS */
    Tile();
    Tile(int x, int y);

    /* INTERFACE */
    void flip();
    void make_current();
    string repr() const;
};

#endif /*_TILE_H_*/
