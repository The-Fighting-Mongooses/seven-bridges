#ifndef _USERINTERFACE_H_
#define _USERINTERFACE_H_

#include <iostream>
#include "Board.h"
using namespace std;

class UserInterface
{
    public:
        UserInterface();

        /*
         * The game engine should call this function when the board state
         * changes.
         *
         * The board needs to be passed in as a parameter so this function may
         * read from it.
         */
        void update(Board const & board);

        /*
         * The game engine should call this function when it is ready to
         * accept user input.
         *
         * Returns 'w', 'a', 's', or 'd' (lowercase intended).
         */
        char get_key_press();
};

#endif //_USERINTERFACE_H_
