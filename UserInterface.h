#ifndef _USERINTERFACE_H_
#define _USERINTERFACE_H_

#include <iostream>
#include <termios.h>

#include "Board.h"

using namespace std;

class UserInterface
{
    private:
        //Used to store the old terminal settings so we may restore them
        struct termios m_old_term_settings;
    public:
        UserInterface();
        ~UserInterface();

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
}

#endif //_USERINTERFACE_H_
