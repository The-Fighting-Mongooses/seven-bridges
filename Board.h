/*******************************************************************************
 * Defines the interface for a Board class, an (up to) 32x32 grid of Locations *
 * for a Hamiltonian Path puzzle.                                              *
 *                                                                             *
 * @author:           TheFightingMongooses                                     *
 * @version:          0.1                                                      *
 * @since:            2014-03-16                                               *
 *******************************************************************************/

#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>
#include "Location.h"
#include "Tile.h"

using namespace std;

//TODO: Check that the pointer logic is correct for m_start+m_player.

class Board
{
  //friend class Location;

  private:	
    vector<vector<Location*>> m_board;
    Tile *m_start, *m_player;
    int m_height, m_width;

  public:
    /* CONSTRUCTORS */
    Board();

    /* UTILITIES */

    // Change the size of the Board.
    void resize_board(const int& x, const int& y);

    // Insert a Location into this Board.
    void insert(Location* loc);

    // Move the player based on user input.
    void update(const char& input);
    Location* make_adjacent_location(const char& input);
    void move(const char& input, int& x, int& y);

    // Determine wether the specified Location is in bounds of the board.
    bool includes(const Location& loc) const;
    bool includes(const int x, const int y) const;

    // Returns the specified Location's character representation.
    char contents_at(const int x, const int y) const;

    // Reset the Board so the player can start over.
    void reset();
};

#endif /*_BOARD_H_*/
