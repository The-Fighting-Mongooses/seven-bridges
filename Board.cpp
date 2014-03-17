#include "Board.h"

Board::Board()
{
  this->m_height = 0;
  this->m_width  = 0;
  
  this->m_player = Location(0, 0);
  this->m_start  = Location(0, 0);
  this->m_finish = Location(0, 0);
}

void Board::resize_board(const int& x, const int& y)
{
  this->m_board.resize(x);
  for (int i = 0; i < x; ++i)
  {
    this->m_board[i].resize(y);
  }

  this->m_width  = x;
  this->m_height = y;
}

string Board::contents_at(const Location& loc) const
{
  int x = loc.m_x;
  int y = loc.m_y;

  if (!this->includes(loc))
    return "\0";
  else return this->m_board[x][y].repr();
}

bool Board::includes(const Location& loc) const
{
  int x = loc.m_x;
  int y = loc.m_y;

  if (x < 0 || x >= this->m_width)
    return false;
  if (y < 0 || y >= this->m_height)
    return false;

  return true;
}

