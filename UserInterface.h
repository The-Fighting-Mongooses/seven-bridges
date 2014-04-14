/*******************************************************************************
 * Defines the interface for a UserInterface class.  Allows user interaction   *
 * with the game via the terminal.  Grabs the user's terminal settings and     *
 * turns off buffering so they may play the game without needing to confirm    *
 * their actions via the enter key.                                            *
 *                                                                             *
 * @author:       TheFightingMongooses                                         *
 * @version:      1.0                                                          *
 * @since:        2014-03-19                                                   *
 *                                                                             *
 ********************************************************************************/
#ifndef _USERINTERFACE_H_
#define _USERINTERFACE_H_

#include <iostream>
#include <deque>
#include <termios.h>
#include <SDL2/SDL.h>
#include "Board.h"

using namespace std;

class UserInterface
{
  private:
    SDL_Window *m_window; // The main window for the GUI.
    SDL_Texture *black_tex, *blue_tex, *red_tex, *green_tex;
    SDL_Renderer *ren;
    char m_hints[6]; // Imagine this would be useful, but feel free to change. <wth>


    //Used to store the old terminal settings so we may restore them
    //struct termios m_old_term_settings;

    //Prints a grid space corresponding to the character provided
    void pretty_print(char c, int x, int y);

    void print_sdl_error(ostream & os, const string & msg);
    SDL_Texture * load_texture(const string & file);
    void blit(SDL_Texture *tex, int x, int y);


  public:
    /* CONSTRUCTORS */
    UserInterface();
    ~UserInterface();

    /* INTERFACE */

    // The game engine should call this function when the board state
    // changes.  The board needs to be passed in as a parameter so this 
    // function may read from it.
    void update(const Board & board);

    // Display a message to the user
    void message(const string & msg, const string & hint);

    // The game engine should call this function when it is ready to
    // accept user input.  Returns 'w', 'a', 's', or 'd' (lowercase 
    // intended).
    char get_key_press();
};

#endif //_USERINTERFACE_H_
