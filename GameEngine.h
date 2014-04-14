/********************************************************************************
 * Defines the interface for a GameEngine class that will manage the gameplay.  *
 *                                                                              *
 * @author:       TheFightingMongooses                                          *
 * @version:      1.0                                                           *
 * @since:        2014-03-19                                                    *
 *                                                                              *
 ********************************************************************************/

#ifndef _GAME_ENGINE_H_ 
#define _GAME_ENGINE_H_

#include "Board.h"
#include "UserInterface.h"
#include "Scanner.h"
using namespace std;

class GameEngine
{
  private:
    Board m_board;
    Scanner m_scanner;
    UserInterface m_ui;

    string m_hints[6];

  public:
    /* CONSTRUCTORS */
    GameEngine();

    /* MAIN GAME LOOP */
    void play();
};

#endif /* _GAME_ENGIE_H_ */
