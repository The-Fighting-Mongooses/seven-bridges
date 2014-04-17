#include <cstdlib>
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <SDL2/SDL.h>

#include "UserInterface.h"
#include "Board.h"
#include "ANSI.h"

using namespace std;

/* Save the current terminal settings and turn off buffering. */
UserInterface::UserInterface()
{
  //Save the current terminal settings, then turn off buffering so we don't
  //have to press enter each time
  //struct termios term_settings;
  //tcgetattr(0, &term_settings);
  //m_old_term_settings = term_settings;
  //term_settings.c_lflag &= ~(ECHO | ICANON);
  //tcsetattr(0, TCSANOW, &term_settings);

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    print_sdl_error(cout, "SDL_Init");
    exit(EXIT_FAILURE);
  }

  m_window = SDL_CreateWindow("Seven Bridges", 100, 100, 0, 0, 
      SDL_WINDOW_SHOWN);
  if (m_window == nullptr) {
    print_sdl_error(cout, "CreateWindow");
    exit(EXIT_FAILURE);
  }

  ren = SDL_CreateRenderer(m_window, -1,
      SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (ren == nullptr) {
    print_sdl_error(cout, "CreateRenderer");
    exit(EXIT_FAILURE);
  }

  black_tex = load_texture("black.bmp");
  blue_tex = load_texture("blue.bmp");
  green_tex = load_texture("green.bmp");
  red_tex = load_texture("red.bmp");
}

/* Print the Location. */
void UserInterface::pretty_print(char c, int x, int y)
{
  switch(c) 
  {
    case 'c':
      //cout << ANSI::yellow_bg << " ";
      blit(green_tex, 40*x, 40*y);
      break;
    case 'u':
      //cout << ANSI::blue_bg << " ";
      blit(blue_tex, 40*x, 40*y);
      break;
    case 'x':
      //cout << ANSI::red_bg << " ";
      blit(red_tex, 40*x, 40*y);
      break;
    case '#': 
      //cout << ANSI::black_fg << ANSI::white_bg << "#";
      blit(black_tex, 40*x, 40*y);
  }
  //cout << ANSI::normal;
}

/* Update the Board representation. */
void UserInterface::update(const Board& board)
{
  static int old_width = -1;
  static int old_height = -1;
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
  /* cli
     cout << "\033[H\033[J" << endl;
     */

  //Only resize if necessary
  if (width != old_width || height != old_height) {
    old_width = width;
    old_height = height;
    SDL_SetWindowSize(m_window, width * 40, height * 40);
  //This fixes the broken rednering when resizing. No idea how.
    sleep(1);
  }


  for (int y = 0; y < height; ++y) 
  {
    for (int x = 0; x < width; ++x) 
    {
      pretty_print(board.contents_at(x, y), x, y);
    }
    //cout << endl;
  }
  SDL_RenderPresent(ren);	
}

/* Prompt the user to advance to the next puzzle or print a message. */
void UserInterface::message(const string& msg, const string& hint)
{
  // Wrap SDL_ShowSimpleMessageBox
  SDL_ShowSimpleMessageBox(
      SDL_MESSAGEBOX_INFORMATION,
      hint.c_str(),
      msg.c_str(),
      m_window);
}

/* Get user input. */
char UserInterface::get_key_press()
{
  while(1) 
  {
    SDL_Event e;
    if (SDL_PollEvent(&e) == 0) {
      continue;
    } else if (e.type == SDL_QUIT) { 
      return 'q';
    } else if (e.type != SDL_KEYDOWN) {
      continue;
    }
    switch (e.key.keysym.scancode) {
      case SDL_SCANCODE_W:
        return 'w';
      case SDL_SCANCODE_A:
        return 'a';
      case SDL_SCANCODE_S:
        return 's';
      case SDL_SCANCODE_D:
        return 'd';
      case SDL_SCANCODE_R:
        return 'r';
      default:
        continue;
    }
  }

  /* cli
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
     */
}

/* Print SDL errors */
void UserInterface::print_sdl_error(ostream &os, const string &msg)
{
  os << msg << " error: " << SDL_GetError() << endl;
}

/* Load BMP image into a texture */
SDL_Texture* UserInterface::load_texture(const string &file)
{
  SDL_Texture *texture = nullptr;

  SDL_Surface *loaded_image = SDL_LoadBMP(file.c_str());

  //If the imaged loaded successfully, convert to texture
  if (loaded_image != nullptr) {
    texture = SDL_CreateTextureFromSurface(ren, loaded_image);
    SDL_FreeSurface(loaded_image);

    if (texture == nullptr) {
      print_sdl_error(cout, "CreateTextureFromSurface");
      exit(EXIT_FAILURE);
    }
  }
  else {
    print_sdl_error(cout, "LoadBMP");
    exit(EXIT_FAILURE);
  }

  return texture;
}

/* Draw texture to renderer at position x, y */
void UserInterface::blit(SDL_Texture *tex, int x, int y)
{
  SDL_Rect destination;
  destination.x = x;
  destination.y = y;

  SDL_QueryTexture(tex, NULL, NULL, &destination.w, &destination.h);
  SDL_RenderCopy(ren, tex, NULL, &destination);
}

/* Free SDL objects and restore original terminal settings. */
UserInterface::~UserInterface()
{
  SDL_DestroyTexture(black_tex);
  SDL_DestroyTexture(red_tex);
  SDL_DestroyTexture(green_tex);
  SDL_DestroyTexture(blue_tex);
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(m_window);
  SDL_Quit();

  //tcsetattr(0, TCSANOW, &m_old_term_settings);
}
