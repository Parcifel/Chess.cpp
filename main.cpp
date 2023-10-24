// Standard libraries
#include <iostream>

// Third party libraries
#include "constants.h"
#include "read.h"
#include "coordinate.h"
#include "board.h"

using namespace std;

int main() {
    string game_name;

    while (true) {
        try {
            game_name = getGame();
            break;
        } catch (runtime_error& e) {
            cout << e.what() << endl;
            continue;
        }
    }

    if (game_name == "") {
        cout << "Program terminated." << endl;
        return 0;
    }

    cout << LINE << endl;
    cout << "Loading game: " << game_name << "..." <<  endl;

    vector<string>* board = readBoard(game_name);
    vector<string>* moves = readMoves(game_name);

    vector<string> board_lines;
    for (int i = 0; i < 8; i++) {
        board_lines.push_back((*board)[i]);
    }
    string status_line = (*board)[8];
    // delete[] board;

    Board board_obj(board_lines, status_line);




    return 0;

}
