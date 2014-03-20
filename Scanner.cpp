#include <fstream>

#include "Scanner.h"
#include "Board.h"
#include "Location.h"
//Probably include subclasses of Location

using namespace std;

Scanner::Scanner(String filename)
{
    //TODO open the file <dcp>
}

bool Scanner::read(Board board)
{
    //TODO read from the file and use functions of Board to feed it in
    return false;
}

Scanner::~Scanner()
{
    //TODO close the file if open
}
