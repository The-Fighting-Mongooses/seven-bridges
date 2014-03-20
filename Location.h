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
    Location();
    Location(int x, int y);

    /* DEBUGGING */
    void print(ostream& out = cerr) const;
    bool is_equal_to(const Location& other) const;

    /* INTERFACE */

    // Return an ASCII representation of this Location so that the display has
    // precise information about what it needs to print.  Should be
    // reimplemented in any class that derives from Location.
    virtual char repr() = 0 const;

    // Reset the location.  Really only useful for a Tile, but it will probably
    // make it easier for the GameEngine and Board if it can expect an Obstacle
    // to have this defined.
    virtual void reset() = 0;

    // Return the Location in the specified location.
    //inline Location north() const { return Location(m_x, m_y-1); }
    //inline Location east() const  { return Location(m_x+1, m_y); }
    //inline Location south() const { return Location(m_x, m_y+1); }
    //inline Location west() const  { return Location(m_x-1, m_y); }
};

#endif /*_LOCATION_H_*/
