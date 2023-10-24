// Tile tiles[8][8];       
// Rewrite into sybol table
// int active_player;
// bool castling[4];
// Coordinate en_passant;
// size_t halfmove_clock;

// void readBoard(vector<string> board_lines);
// void readStatus(string status_line);

// void validateBoard(vector<string> board_lines);
// void validateStatus(string status_line);

// public:

// Board();
// Board(vector<string> board_lines, string status_line);

// Tile getTile(Coordinate coordinate);
// Tile getTile(int x, int y);

// int activePlayer();
// bool canCastle(int player, bool king_side);
// Coordinate enPassant();
// size_t halfmoveClock();

// bool isInitialBoard();

#include "constants.h"
#include "board.h"
#include "tile.h"
#include "piece.h"
#include "coordinate.h"

#include"debug.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Board::readBoard(vector<string>& board_lines) {
    if (board_lines.size() != 8) {
        cerr << "Invalid board: length[8] != " << board_lines.size() << endl;
        this->is_valid = false;
        return;
    }

    try {
        this->validateBoard(board_lines);
        this->is_valid = true;
    } catch (Coordinate& c) {
        cerr << "Invalid board: " << c.getTile() << endl;
        this->is_valid = false;
    }
}
void Board::readStatus(string& status_line) {
    try {
        this->validateStatus(status_line);
        this->is_valid = true;
    } catch (Coordinate& c) {
        cerr << "Invalid status: " << c.getTile() << endl;
        this->is_valid = false;
    }
}

void Board::validateBoard(vector<string>& board_lines) {
    dout("Board");
    for (string line : board_lines) {
        dout(line);
    }
    return;
}
void Board::validateStatus(string& status_line) {
    dout("Status");
    for (size_t i=0; i<status_line.length(); i++) {
        if (status_line[i] != ' ') {
            dout(status_line[i]);
        }
    }
    return;
}

Board::Board() {
    /**
     * This constructor will create an empty board.
     * It will initialize the board with the following:
     * 1. All tiles are empty
     * 2. Active player is white
     * 3. Castling is allowed for both players
     * 4. En passant is not allowed
     * 5. Halfmove clock is 0
    */
   dout("Initializing Empty Board ...");

    // Initialize all tiles to empty
    for (size_t row=0; row<8; row++) {
        for (size_t col=0; col<8; col++) {
            this->tiles[row][col] = Tile();
        }   
    }

    // This is an initial Status
    // player: White
    // castling: all true
    // en passant: null
    // halfmove clock: 0
    this->active_player = 0;
    for (size_t i=0; i<4; i++) {
        this->castling[i] = true;
    }
    this->en_passant = Coordinate();
    this->halfmove_clock = 0;
}
Board::Board(vector<string> board_lines, string status_line) {
    /**
     * This constructor will create a board from a vector of strings.
     * The vector of strings will be the board, and the string will be the status.
     * 
     * The board will be validated before being created.
     * The status will be validated before being created.
    */
    dout("Initializing Board ...");

    this->readBoard(board_lines);
    this->readStatus(status_line);
}

// Tile getTile(Coordinate coordinate);
// Tile getTile(int x, int y);

// int activePlayer();
// bool canCastle(int player, bool king_side);
// Coordinate enPassant();
// size_t halfmoveClock();

// bool isInitialBoard();