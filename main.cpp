// Standard libraries
#include <iostream>

// Third party libraries
#include "constants.h"
#include "read.h"

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

    vector<string> board = readBoard(game_name);
    vector<string> moves = readMoves(game_name);

    cout << LINE << endl;
    cout << "Board: " << endl;
    for (string line : board) {
        cout << line << endl;
    }

    cout << LINE << endl;
    cout << "Moves: " << endl;
    for (string move : moves) {
        cout << move << endl;
    }



    return 0;

}