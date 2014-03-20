#ifndef _GAME_ENGINE_H_ 
#define _GAME_ENGINE_H_

#include "Board.h"
using namespace std;

class GameEngine
{
  private:
    Board m_board;
    Scanner m_scanner;
    UserInterface m_ui;

  public:
    /* CONSTRUCTORS */
    GameEngine() {}

    /* MAIN GAME LOOP */
    void play();
};

#endif /* _GAME_ENGIE_H_ */
