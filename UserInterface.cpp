#include <iostream>
#include <termios.h>
#include <unistd.h>

#include "UserInterface.h"
#include "Board.h"

using namespace std;

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

void UserInterface::pretty_print(char c)
{
   switch(c) {
       case 'c':
           cout << "\e[43m" << " " << endl;
           break;
       case 'u':
           cout << "\e[44m" << " " << endl;
           break;
       case 'x':
           cout << "\e[41m" << " " << endl;
           break;
       case '#': 
           cout << "\e[47m\e[30m" << "#" << endl;
   }
   cout << "\e[0m";
}

void UserInterface::update(Board const & board)
{
    int width = board.get_width();
    int height = board.get_height();

    //TODO this isn't portable, so find a better way to clear screen
    cout << "\033[H\033[J" << endl;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            pretty_print(board.contents_at(x, y));
        }
        cout << endl;
    }
}

void UserInterface::message(string const & msg)
{
    //TODO
    //Do we want this to be press any key to continue? Or what?
}

char UserInterface::get_key_press()
{
    while(1) {
        char c;
        int error = read(0, &c, sizeof(char));
        if (error < 0) {
            perror("read");
        }

        switch (c) {
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

UserInterface::~UserInterface()
{
    tcsetattr(0, TCSANOW, &m_old_term_settings);
}

/*
int main(int argc, char **argv)
{
    UserInterface ui;
    cout << "Waiting a moment..." << endl;
    sleep(5);
    for (int i = 0; i < 5; ++i) {
        cout << ui.get_key_press() << endl;
    }
}
*/
