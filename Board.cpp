#include "Board.h"
#include "Location.h"
#include "Tile.h"

/* Typical Constructor.  Initialize all of this Board's elements. */
Board::Board()
{
  this->m_height = 0;
  this->m_width  = 0;
  
  this->m_start  = nullptr;
  this->m_player = this->m_start;
}

/* Return the width and height of the board */
int Board::get_width() const
{
    return m_width;
}

int Board::get_height() const
{
    return m_height;
}

/* Change the size of the board using the specified width and height. */
void Board::resize_board(const int& x, const int& y)
{
  for (int i = 0; i < m_board.size(); ++i) {
      for (int j = 0; j < m_board.at(i).size(); ++j) {
          if (m_board.at(i).at(j) != nullptr) {
              delete m_board.at(i).at(j);
          }
      }
      m_board.at(i).clear();
  }
  m_board.clear();
  this->m_board.resize(x);
  for (int i = 0; i < x; ++i)
  {
    this->m_board[i].resize(y);
    for (int j = 0; j < y; ++j) {
        m_board.at(i).at(j) = nullptr;
    }
  }

  this->m_width  = x;
  this->m_height = y;
}

/* Insert a Location into this Board. */
void Board::insert(Location* loc)
{
  int x = loc->m_x;
  int y = loc->m_y;

  if (m_board.at(x).at(y) != nullptr) {
      delete m_board.at(x).at(y);
  }

  this->m_board.at(x).at(y) = loc;

  // If the location is marked as current, it is the staring location.
  // Move the player here.
  if (loc->repr() == 'c')
  {
    this->m_start = static_cast<Tile*>(loc);
    this->m_player = this->m_start;
  }
}

/* Move the player based on user input. */
void Board::update(const char& input)
{
  Location* loc = this->make_adjacent_location(input);
  if (loc->repr() == '#' || loc->repr() == 'u')
    return;

  // Flip the tile, and move the player to the new location.
  this->m_player->flip();
  this->m_player = static_cast<Tile*>(loc);
  this->m_player->make_current();
}

/* Return the Location in the direction specified. */
Location* Board::make_adjacent_location(const char& input)
{
  int x = m_player->m_x;
  int y = m_player->m_y;

  this->move(input, x, y);
  return this->m_board[x][y];
}

/* Move the coordinates in the direction specified. */
void Board::move(const char& input, int& x, int& y)
{
  switch (input)
  {
    case 'w':
      --y;
      break;
      
    case 'a':
      --x;
      break;

    case 's':
      ++y;
      break;

    case 'd':
      ++x;
      break;
  }
}

//Changed because using a Location to get a Location didn't make as much sense <dcp>
/* Return the character representation of the specified locatioun. */
char Board::contents_at(const int x, const int y) const
{

  if (!this->includes(x, y))
    return '\0';
  else return this->m_board[x][y]->repr();
}

/* Determine if the specified Location is in bounds of the Board. */
bool Board::includes(const Location& loc) const
{
  int x = loc.m_x;
  int y = loc.m_y;

  return includes(x, y);
}

//Added overloaded includes for contents_at, which had to be changed <dcp>
/* Determine if the specified Location is in bounds of the Board. */
bool Board::includes(const int x, const int y) const
{
  if (x < 0 || x >= this->m_width)
    return false;
  if (y < 0 || y >= this->m_height)
    return false;

  return true;
}

/* Reset the Board so the player may start over. */
void Board::reset()
{
  // Reset the tiles.
  for (int i = 0; i < this->m_width; ++i) 
  {
    for (int j = 0; j < this->m_height; ++j)
    {
      this->m_board[i][j]->reset();
    }
  }

  // Move the player back to the starting position.
  this->m_player = this->m_start;

  int x = m_player->m_x;
  int y = m_player->m_y;
  static_cast<Tile*>(this->m_board[x][y])->make_current();
}

/* Check if puzzle is solved */
bool Board::check_solved()
{
    for (int i = 0; i < m_width; ++i)
    {
        for (int j = 0; j < m_height; ++j) {
            if (m_board[i][j]->repr() == 'x')
                return false;
        }
    }
    return true;
}
