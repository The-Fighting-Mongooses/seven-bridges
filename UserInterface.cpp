#include <iostream>
#include <termios.h>
#include <unistd.h>

#include "UserInterface.h"
#include "Board.h"
#include "ANSI.h"

using namespace std;

/* Save the current terminal settings and turn off buffering. */
UserInterface::UserInterface()
{
  //Save the current terminal settings, then turn off buffering so we don't
  //have to press enter each time
  struct termios term_settings;
  tcgetattr(0, &term_settings);
  m_old_term_settings = term_settings;
  term_settings.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(0, TCSANOW, &term_settings);
}

/* Print the Location. */
void UserInterface::pretty_print(char c)
{
  switch(c) 
  {
    case 'c':
      cout << ANSI::yellow_bg << " ";
      break;
    case 'u':
      cout << ANSI::blue_bg << " ";
      break;
    case 'x':
      cout << ANSI::red_bg << " ";
      break;
    case '#': 
      cout << ANSI::black_fg << ANSI::white_bg << "#";
  }
  cout << ANSI::normal;
}

/* Update the Board representation. */
void UserInterface::update(const Board& board)
{
  int width = board.get_width();
  int height = board.get_height();

  //TODO this isn't portable, so find a better way to clear screen
  //Why doesn't "\e[2J" work?  Also, there is an "ANSI.h" file. :-)
  //More importantly, does this matter? The intent is that the GUI
  //is portable, right? <wth>
  //
  //Because that only works on systems that interpret ANSI escape codes. Also,
  //that does not reposition the cursor in the upper left. And it doesn't matter
  //that much, or this would have been done by now. And your ANSI.h file was
  //complicated. It was faster to just do this. <dcp>
  cout << "\033[H\033[J" << endl;

  for (int y = 0; y < height; ++y) 
  {
    for (int x = 0; x < width; ++x) 
    {
      pretty_print(board.contents_at(x, y));
    }
    cout << endl;
  }
}

/* Prompt the user to advance to the next puzzle or print a message. */
void UserInterface::message(const string& msg, const string& hint)
{
  window = this->m_window;
  // Wrap SDL_ShowSimpleMessageBox
  SDL_ShowSimpleMessageBox(
      SDL_MESSAGEBOX_INFORMATION,
      hint,
      msg,
      window);
}

/* Get user input. */
char UserInterface::get_key_press()
{
  while(1) 
  {
    char c;
    int error = read(0, &c, sizeof(char));
    if (error < 0) 
    {
      perror("read");
    }

    switch (c) 
    {
      case 'w':
      case 'W':
        return 'w';
      case 'a':
      case 'A':
        return 'a';
      case 's':
      case 'S':
        return 's';
      case 'd':
      case 'D':
        return 'd';
      case 'r':
      case 'R':
        return 'r';
    }
  }
}

/* Restore original terminal settings. */
UserInterface::~UserInterface()
{
  tcsetattr(0, TCSANOW, &m_old_term_settings);
}
