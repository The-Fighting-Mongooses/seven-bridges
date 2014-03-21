#include <fstream>

#include "GameEngine.h"
#include "Scanner.h"
#include "UserInterface.h"

using namespace std;

void GameEngine::play()
{
    string line;
    ifstream board_names("BoardNames.txt");

    if (board_names.is_open()) {
        while (getline(board_names, line)) {
            m_scanner.read(line);

            m_ui.update(m_board);
            while (m_board.check_solved() ==  false) {
                char keypress = m_ui.get_key_press();

                if (keypress == 'r')
                    m_board.reset();
           
                else 
                    m_board.update(keypress);

                m_ui.update(m_board);
            }
        }
    }
}

GameEngine::GameEngine() : m_scanner(m_board) { }
