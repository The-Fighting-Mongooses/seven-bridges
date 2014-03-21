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

Scanner::Scanner(string filename) : file("Board1.txt")
{
    //TODO open the file <dcp>
    //file.open ("Board1.txt");
  
}

bool Scanner::read(Board board)
{
    //TODO read from the file and use functions of Board to feed it in
    //return false;

    //ifstream file ("Board1.txt");
       if (file.is_open())
       {
          while (getline (file,line))
          {
             cout << line << '\n';
          }
       }   
       else cout << "Unable to open";
    
       return false;
}

Scanner::~Scanner()
{
    //TODO close the file if open
    file.close();
}
