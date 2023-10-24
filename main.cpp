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

    // vector<string> board_lines;
    // for (int i = 0; i < 8; i++) {
    //     board_lines.push_back((*board)[i]);
    // }
    // string status_line = (*board)[8];
    // delete[] board;

    Board board_obj(*board);

    cout << "Board loaded." << endl;
    cout << LINE << endl;

    cout << "BOARD:" << endl;
    cout << board_obj.toString() << endl;

    cout << "STATUS: " << endl;
    cout << "Active player: " << board_obj.activePlayer() << endl;
    cout << "Can castle(W KS): " << board_obj.canCastle(WHITE, true) << endl;
    cout << "Can castle(W QS): " << board_obj.canCastle(WHITE, false) << endl;
    cout << "Can castle(B KS): " << board_obj.canCastle(BLACK, true) << endl;
    cout << "Can castle(B QS): " << board_obj.canCastle(BLACK, false) << endl;
    if (board_obj.enPassant().isValid()) {
        cout << "En passant: " << board_obj.enPassant().getTile() << endl;
    } else {
        cout << "En passant: None" << endl;
    }
    cout << "Halfmove clock: " << board_obj.halfmoveClock() << endl;



    return 0;

}
