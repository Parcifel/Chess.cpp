#ifndef BOARD_H
#define BOARD_H

#include "tile.h"
#include "piece.h"  
#include "coordinate.h"

#include <string>
#include <vector>


class Board {
    private:
        Tile tiles[8][8];

        // Rewrite into sybol table
        int active_player;
        bool castling[4];
        Coordinate en_passant;
        size_t halfmove_clock;

        bool is_valid = false;

        void readBoard(vector<string>& board_lines);
        void readStatus(string& status_line);

        void validateBoard(vector<string>& board_lines);
        void validateStatus(string& status_line);

    public:

        Board();
        Board(vector<string> board_lines, string status_line);

        Tile getTile(Coordinate coordinate);
        Tile getTile(int x, int y);

        int activePlayer();
        bool canCastle(int player, bool king_side);
        Coordinate enPassant();
        size_t halfmoveClock();

        bool isInitialBoard();


};


#endif // BOARD_H