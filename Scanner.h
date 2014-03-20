#ifndef _SCANNER_H_
#define _SCANNER_H

#include <fstream>

#include "Board.h"

using namespace std;

class Scanner
{
    public:
        /*
         * Create a scanner to read a board from the passed in file name
         */
        Scanner(String filename);

        /*
         * Feed the data from the saved board file into the actual board
         */
        read(Board board);

        /*
         * Close any open files
         */
        ~Scanner();
}
