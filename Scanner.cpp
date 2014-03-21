#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "Scanner.h"
#include "Board.h"
#include "Location.h"
#include "Obstacle.h"
#include "Tile.h"
//Probably include subclasses of Location

using namespace std;

/* Initialize the scanner with the passed Board. */
Scanner::Scanner(Board &board) 
  : m_board(board)
{

}

/* Read the Board from a file. */
bool Scanner::read(string filename)
{
  int width, height;
  string line;
  int lineno = 0;

  ifstream file (filename);
  file >> width >> height >> ws;

  this->m_board.resize_board(width, height);

  // Read the file one line at a time.
  while (getline (file,line))
  {
    // Remove the newline character.
    if (line.back() == '\n') 
    {
      line.pop_back();
    }

    // Create the Board one location at a time.
    for (int i = 0; i < line.length(); ++i) 
    {
      Location *loc;
      switch (line.at(i)) 
      {
        case '#': // Wall or Obstacle
          loc = new Obstacle(i, lineno);
          break;

        case 'c': // The starting position
          loc = new Tile(i, lineno);
          static_cast<Tile*>(loc)->make_current();
          break;

        default: // Ordinary Tile
          loc = new Tile(i, lineno);
      }

      this->m_board.insert(loc);
    }
    lineno++;
  }

  file.close();
  return true;
}

/* Destructor.  Nothing to do here (yet?). */
Scanner::~Scanner()
{

}
