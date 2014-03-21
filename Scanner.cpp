#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "Scanner.h"
#include "Board.h"
#include "Location.h"
#include "Obstacle.h"
#include "Tile.h"
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
    file >> width >> height >> ws;

    m_board.resize_board(width, height);

    while (getline (file,line))
    {
        if (line.back() == '\n') {
            line.pop_back();
        }
            
        for (int i = 0; i < line.length(); ++i) {
            Location *tmp;
            switch (line.at(i)) {
                case '#':
                    tmp = new Obstacle(i, lineno);
                    break;
                case 'c':
                    tmp = new Tile(i, lineno);
                    static_cast<Tile*>(tmp)->make_current();
                    break;
                default:
                    tmp = new Tile(i, lineno);
            }
            m_board.insert(tmp);
        }
        lineno++;
    }
    //else cout << "Unable to open";

    file.close();

    return true;
}

Scanner::~Scanner()
{
}
