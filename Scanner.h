/********************************************************************************
 * Defines the interface for a Scanner class.  Used to read a Board represent-  *
 * ation from a file and pass it to the GameEngine.                             *
 *                                                                              *
 * @author:         TheFightingMongooses                                        *
 * @version:        1.0                                                         *
 * @since:          2014-03-19                                                  *
 *                                                                              *
 ********************************************************************************/

#ifndef _SCANNER_H_
#define _SCANNER_H_

#include <fstream>

#include "Board.h"

using namespace std;

class Scanner
{
  private:
    Board &m_board;
  
  public:
    /* CONSTRUCTORS */

    //Store the board for future use.
    Scanner(Board &board);

    ~Scanner();

    /* UTILITIES */

    // Feed the data from the saved board file into the actual board
    bool read(string filename);


};
#endif 
