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

void UserInterface::update(Board const & board)
{
    //TODO print the board <dcp>
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
