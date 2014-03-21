#include <fstream>
#include <iostream>
#include <string>
#include "Scanner.h"
#include "Board.h"
#include "Location.h"
//Probably include subclasses of Location

using namespace std;

int WIDTH;
int HEIGHT;
string line;

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
    //TODO read from the file and use functions of Board to feed it in
    //return false;

    ifstream file (filename);
          while (getline (file,line))
          {
             cout << line << '\n';
          }
       else cout << "Unable to open";
    
       return false;
}

Scanner::~Scanner()
{
}
