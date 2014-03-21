/************************************************************
 * Defines the interface for a Location class, essentially  *
 * represents any spot on a 32x32 puzzle grid.  While used  *
 * internally, it is meant to be abstract in the sense that *
 * any instance ultimately used in the maze should be of    *
 * one of the derived types.                                *
 *                                                          *
 * @author:             TheFightingMongooses                *
 * @version:            0.1                                 *
 * @since:              2014-02-04                          *
 *                                                          *
 ************************************************************/

#ifndef _LOCATION_H_
#define _LOCATION_H_

#include <fstream>
#include <iostream>
using namespace std;

class Location
{
  // Not necessary, but it makes some of the Board methods easier to write
  // if it has access to the coordinates of its Locations.
  friend class Board;

  protected:
    int m_x;
    int m_y;

  public:
    /* CONSTRUCTORS */
    Location(int x, int y);
    virtual ~Location();

    /* DEBUGGING */
    void print(ostream& out = cerr) const;
    bool is_equal_to(const Location& other) const;

    /* INTERFACE */

    // Return an ASCII representation of this Location so that the display has
    // precise information about what it needs to print.  Should be
    // reimplemented in any class that derives from Location.
    virtual char repr() const = 0;

    // Reset the location.  Really only useful for a Tile, but it will probably
    // make it easier for the GameEngine and Board if it can expect an Obstacle
    // to have this defined.
    virtual void reset() = 0;
};

#endif /*_LOCATION_H_*/
