#include <fstream>
#include <iostream>
#include <string>
#include "Scanner.h"
#include "Board.h"
#include "Location.h"
//Probably include subclasses of Location

using namespace std;

//int WIDTH;
//int HEIGHT;

//ofstream file ("Board1.txt");

/*struct point
{
   int x;
   int y;
};*/

Scanner::Scanner(Board &board) : m_board(board)
{
}

bool Scanner::read(string filename)
{
    int width, height;
    string line;
    int lineno = 0;

    ifstream file (filename);
    cin >> width >> height;

    m_board.resize(width, height);

    while (getline (file,line))
    {
        for (int i = 0; i < line.length(); ++i) {
            Location *tmp;
            switch (line.at(i)) {
                case '#':
                    break;
                    tmp = new Obstacle(i, lineno);
                case 'c':
                    tmp = new Tile(i, lineno);
                    tmp->make_current();
                    break;
                default:
                    tmp = new Tile(i, lineno);
            }
            m_board.insert(tmp);
        }
    }
    //else cout << "Unable to open";

    return true;
}

Scanner::~Scanner()
{
}
