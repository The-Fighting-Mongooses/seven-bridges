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
