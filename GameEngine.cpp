#include <fstream>

#include "GameEngine.h"
#include "Board.h"
#include "Scanner.h"
#include "UserInterface.h"

using namespace std;

/* Initialize the GameEngine. */
GameEngine::GameEngine() 
  : m_scanner(this->m_board) 
{ 

}

/* Main Game Loop */
void GameEngine::play()
{
  string line;
  ifstream board_names("BoardNames.txt");

  if (board_names.is_open()) 
  {
    while (getline(board_names, line)) 
    {
      this->m_scanner.read(line);

      this->m_ui.update(this->m_board);
      while (!this->m_board.check_solved()) 
      {
        char keypress = this->m_ui.get_key_press();

        if (keypress == 'r')
          this->m_board.reset();

        else 
          this->m_board.update(keypress);

        this->m_ui.update(m_board);
      }
    }

    board_names.close();
  }
}
