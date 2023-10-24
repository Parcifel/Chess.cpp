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


/* READING */
void Board::readBoard(vector<string>& board_lines) {
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
    } catch (runtime_error& e) {
        cerr << "Invalid status: " << &e << endl;
        this->is_valid = false;
    }
}

/* VALIDATION */
void Board::validateBoard(vector<string>& board_lines) {
    dout("Board");  

    Coordinate current_coordinate;

    //! <VB1> Board lines is empty
    if (board_lines.size() == 0) {
        dout("VB1");
        throw Coordinate(0, 0);
    }


    for (size_t row=0; row<8; row++) {

        //! <VB2> No more lines
        if (row >= board_lines.size()) {
            dout("VB2");
            throw Coordinate(0, row);
        }

        string line = board_lines[row];

        for (size_t col=0; col<8; col++) {
            current_coordinate.setCoordinate(col, row);

            //! <VB3> No more tiles
            if (col >= line.length()) {
                dout("VB3");
                throw current_coordinate;
            }

            char tile = line[col];
            int player = (tile >= 'A' && tile <= 'Z') ? 0 : 1;
            tile = (tile >= 'A' && tile <= 'Z') ? tile - 'A' + 'a' : tile;

            //! <VB4> Invalid Occupant
            switch (tile) {
            case '.': // Empty tile
                tiles[row][col] = Tile();
                break;

            case 'p': // Pawn
                tiles[row][col] = Tile(new Pawn(player));
                break;
            
            case 'r': // Rook
                tiles[row][col] = Tile(new Rook(player));
                break;

            case 'n': // Knight
                tiles[row][col] = Tile(new Knight(player));
                break;

            case 'b': // Bishop
                tiles[row][col] = Tile(new Bishop(player));
                break;

            case 'q': // Queen
                tiles[row][col] = Tile(new Queen(player));
                break;

            case 'k': // King
                tiles[row][col] = Tile(new King(player));
                break;
            
            default:
                dout("VB4");
                throw current_coordinate.getTile();
                break;
            }

        }

    }

    return;
}
void Board::validateStatus(string& status_line) {
    vector<string> status_array;

    dout("Status");

    string line = "";
    for (size_t i=0; i<status_line.length(); i++) {
        if (status_line[i] == ' ') {
            status_array.push_back(line);
            line = "";
        } else {
            line += status_line[i];
        }
    }
    status_array.push_back(line);

    //! <VS1> Invalid length
    if (status_array.size() != 4) {
        dout("VS1");
        throw runtime_error("Invalid Status");
    }

    //! <VS2> Invalid Player
    if (status_array[0].length() != 1) {
        dout("VS2");
        throw runtime_error("Invalid Player");
    }
    if (status_array[0] != "w" && status_array[0] != "b") {
        dout("VS2");
        throw runtime_error("Invalid Player");
    }
    this->active_player = (status_array[0] == "w") ? WHITE : BLACK;

    //! <VS3> Castling
    if (status_array[1].length() != 4) {
        dout("VS2");
        throw runtime_error("Invalid Castling");
    }
    for (size_t i=0; i<4; i++) {
        if (status_array[1][i] != '+' && status_array[1][i] != '-') {
            dout("VS2");
            throw runtime_error("Invalid Castling");
        }
        this->castling[i] = (status_array[1][i] == '+') ? true : false;
    }

    //! <VS4> En Passant
    if (status_array[2] == "-") {
        this->en_passant = Coordinate();
    } else {
        try {
            this->en_passant = Coordinate(status_array[2]);
        } catch (Coordinate& c) {
            dout("VS3");
            throw runtime_error("Invalid En Passant");
        }
    } 

    //! <VS4> Halfmove Clock
    try {
        this->halfmove_clock = stoi(status_array[3]);
    } catch (invalid_argument& e) {
        dout("VS4");
        throw runtime_error("Invalid Halfmove Clock");
    }

    return;
}

/* CONSTRUCTORS */
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
Board::Board(vector<string> lines) {
    /**
     * This constructor will create a board from a vector of strings.
     * The vector of strings will be the board, and the status will be empty.
     * 
     * The board will be validated before being created.
     * The status will be validated before being created.
    */
    dout("Initializing Board ...");

    // Validate that there are 9 lines
    if (lines.size() != 9) {
        cerr << "Invalid board: length[9] != " << lines.size() << endl;
        this->is_valid = false;
        return;
    }

    // Split the lines into board and status
    vector<string> board_lines;
    for (int i = 0; i < 8; i++) {
        board_lines.push_back(lines[i]);
    }
    string status_line = lines[8];

    this->readBoard(board_lines);
    this->readStatus(status_line);
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

/* GETTTERS */
// Tile getTile(Coordinate coordinate);
Tile Board::getTile(int row, int col) {
    return this->tiles[row][col];
}

int Board::activePlayer() {
    return this->active_player;
}
bool Board::canCastle(int player, bool king_side) {
    return this->castling[player * 2 + king_side];
}
Coordinate Board::enPassant() {
    return this->en_passant;
}
size_t Board::halfmoveClock() {
    return this->halfmove_clock;
}

/* STATES */
// bool isInitialBoard();


/* TOSTRING*/
string Board::toString() {
    string output;
    for (size_t row=0; row<8; row++) {
        string line = "";
        for (size_t col=0; col<8; col++) {
            if (getTile(row, col).isOccupied()) {
                line += getTile(row, col).getOccupant()->toString();
            } else {
                line += ".";
            } 
        }

        output += line + "\n";
    }

    return output;    
}

/* OPERATORS */
