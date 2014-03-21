#ifndef _SCANNER_H_
#define _SCANNER_H_

#include <fstream>

#include "Board.h"

using namespace std;

class Scanner
{
    public:
        /*
         * Store the board for future use
         */
        Scanner(Board &board);

        /*
         * Feed the data from the saved board file into the actual board
         */
        bool read(string filename);

        ~Scanner();

     private:
         Board &m_board;
};
#endif 
