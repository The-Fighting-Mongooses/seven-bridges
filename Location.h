/************************************************************
 * Defines the interface for a Location class, essentially  *
 * represents any spot on a 32x32 puzzle grid.  While used  *
 * internally, it is meant to be abstract in the sense that *
 * any instance ultimately used in the maze should be of    *
 * one of the derived types.                                *
 *                                                          *
 * @author:             William Hollingsworth               *
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
    virtual string repr() const;

    inline Location north() const { return Location(m_x, m_y-1); }
    inline Location east() const  { return Location(m_x+1, m_y); }
    inline Location south() const { return Location(m_x, m_y+1); }
    inline Location west() const  { return Location(m_x-1, m_y); }
};

#endif /*_LOCATION_H_*/
