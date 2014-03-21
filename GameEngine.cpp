#include "GameEngine.h"
#include "Scanner.h"
using namespace std;

void GameEngine::play()
{
    while ( /* more puzzles */ ) {
        m_scanner.read(m_board);

        while (m_board.check_solved() == false) {
            char keypress = m_ui.get_key_press();

            if (keypress == 'r')
                m_board.reset();
           
            else 
                m_board.update(keypress); 
    }
}

GameEngine::GameEngine() : m_scanner("Board1.txt")
{
    m_ui();
}
