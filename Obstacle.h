/********************************************************************************
 * Defines the interface for an obstacle class.  These act as Locations which   *
 * user is prohibited from traversing.                                          *
 *                                                                              *
 * @author:            TheFightingMongooses                                     *
 * @version:           1.0                                                      *
 * @since:             2014-03-20                                               *
 *                                                                              *
 ********************************************************************************/

#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

#include "Location.h"

class Obstacle : public Location
{
  private:
    typedef Location super;

  public:
    /* Constructors */
    Obstacle(int x, int y);

    /* Interface */
    char repr() const;  // Return a character representation of this Obstacle
    void reset();
};

#endif // _OBSTACLE_H_
