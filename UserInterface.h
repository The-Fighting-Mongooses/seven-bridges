/********************************************************************************
 * Defines the interface for a UserInterface class.  Allows user interaction    *
 * with the game via the terminal.  Grabs the user's terminal settings and      *
 * turns off buffering so they may play the game without needing to confirm     *
 * their actions via the enter key.                                             *
 *                                                                              *
 * @author:       TheFightingMongooses                                          *
 * @version:      1.0                                                           *
 * @since:        2014-03-19                                                    *
 *                                                                              *
 ********************************************************************************/
#ifndef _USERINTERFACE_H_
#define _USERINTERFACE_H_

#include <iostream>
#include <termios.h>
#include <SDL2/SDL.h>
#include "Board.h"

using namespace std;

class UserInterface
{
  private:
    SDL_Window* m_window; // The main window for the GUI.
    char m_hints[6]; // Imagine this would be useful, but feel free to change. <wth>

    //Used to store the old terminal settings so we may restore them
    struct termios m_old_term_settings;
    void pretty_print(char c);

  public:
    /* CONSTRUCTORS */
    UserInterface();
    ~UserInterface();

    /* INTERFACE */

    // The game engine should call this function when the board state
    // changes.  The board needs to be passed in as a parameter so this 
    // function may read from it.
    void update(const Board& board);

    // Display a message to the user
    void message(const string& msg);

    // The game engine should call this function when it is ready to
    // accept user input.  Returns 'w', 'a', 's', or 'd' (lowercase 
    // intended).
    char get_key_press();
};

#endif //_USERINTERFACE_H_
