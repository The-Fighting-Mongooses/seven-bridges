/******************************************
 * Implementation for the Location class. *
 ******************************************/

#include "Location.h"

/* Default consttructor.  Values may change to -1 later. */
Location::Location()
{
  this->m_x = 0;
  this->m_y = 0;
}

/* Typical constructor.  Create a Location at a user defined point. */
Location::Location(int x, int y)
{
  this->m_x = x;
  this->m_y = y;
}

/* Print this Location as a coordinate pair. */
void Location::print(ostream& out) const
{
  out << "(" << this->m_x << "," << this->m_y << ")" << endl;
}

/* Determine if this Location is equivalent to another. */
bool Location::is_equal_to(const Location& other) const
{
  if (this->m_x == other.m_x && this->m_y == other.m_y
      && this->repr() == other.repr()) 
    return true;
  else return false;
}

/* Returns a string representation of this Location. */
string Location::repr() const
{
  return "";
}
