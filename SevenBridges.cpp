#include <iostream>
#include "Location.h"
#include "Tile.h"
using namespace std;

int main(int argc, char* argv[])
{
  Tile t(3, 4);
  //Location l(3, 4);

  t.print();
  cout << t.repr();
  t.make_current();
  cout << t.repr();
  t.flip();
  cout << t.repr() << endl;

  //cout << t.is_equal_to(t) << " " << t.is_equal_to(l) << endl;

  return 0;
}
