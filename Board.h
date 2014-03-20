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

class Board
{
  //friend class Location;

  protected:
    vector<vector<Location>> m_board;
    Location m_start, m_finish, m_player;
    int m_height, m_width;

  public:
    /* CONSTRUCTORS */
    Board();

    /* UTILITIES */

    // Change the size of the Board.
    void resize_board(const int& x, const int& y);

    // Determine wether the specified Location is in bounds of the board.
    bool includes(const Location& loc) const;

    // Returns the specified Location's character representation.
    char contents_at(const Location& loc) const;
};

#endif /*_BOARD_H_*/
