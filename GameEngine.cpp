#include "GameEngine.h"
#include "Scanner.h"
#include "UserInterface.h"
using namespace std;

void GameEngine::play()
{
    while ( 1 /* more puzzles */ ) {
        m_scanner.read("Board1.txt");

        while (/*m_board.check_solved() == */ false) {
            char keypress = m_ui.get_key_press();

            if (keypress == 'r')
                m_board.reset();
           
            else 
                m_board.update(keypress); 
        }
    }
}

GameEngine::GameEngine() : m_scanner(m_board) { }
