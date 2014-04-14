#include <cstdlib>
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

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		log_sdl_error(cout, "SDL_Init");
		return 1;
	}

	SDL_Window *m_window = SDL_CreateWindow("Seven Bridges", 0, 0, SCREEN_WIDTH,			SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (m_window == nullptr) {
		log_sdl_error(cout, "CreateWindow");
		return 2;
	}

	SDL_Renderer *ren = SDL_CreatRenderer(m_window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		log_sdl_error(cout, "CreateRenderer");
		return 3;
	}

	black_tex = load_tex("black.bmp");
	blue_tex = load_tex("blue.bmp");
	green_tex = load_tex("green.bmp");
	red_tex = load_tex("red.bmp");
}

/* Print the Location. */
void UserInterface::pretty_print(char c)
{
	switch(c) 
	{
		case 'c':
			//cout << ANSI::yellow_bg << " ";
			blit(green_tex, 40, 40);
			break;
		case 'u':
			//cout << ANSI::blue_bg << " ";
			blit(blue_tex, 40, 40);
			break;
		case 'x':
			//cout << ANSI::red_bg << " ";
			blit(red_tex, 40, 40);
			break;
		case '#': 
			//cout << ANSI::black_fg << ANSI::white_bg << "#";
			blit(black_tex, 40, 40);
	}
	//cout << ANSI::normal;
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
  //cout << "\033[H\033[J" << endl;

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

/* Print SDL errors */
void print_sdl_error(ostream &os, const string msg)
{
	os << msg << " error: " << SDL_GetError() << endl;
}

/* Load BMP image into a texture */
SDL_Texture* load_texture(const string &file)
{
	SDL_Texture *texture = nullptr;

	SDL_Surface *loaded_image = SDL_LoadBMP(file.c_str());

	//If the imaged loaded successfully, convert to texture
	if (loaded_image != nullptr) {
		texture = SDL_CreateTextureFromSurface(ren, loaded_image);
		SDL_FreeSurface(loaded_image);

		if (texture == nullptr) {
			log_sdl_error(cout, "CreateTextureFromSurface");
			exit(EXIT_FAILURE);
		}
	}
	else {
		log_sdl_error(cout, "LoadBMP");
		exit(EXIT_FAILURE);
	}

	return texture;
}

/* Draw texture to renderer at position x, y */
void blit(SDL_Texture *tex, int x, int y)
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

  tcsetattr(0, TCSANOW, &m_old_term_settings);
}
