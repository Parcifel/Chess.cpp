#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <iostream>
#include <string_view>

using namespace std;

class Piece {
    friend ostream& operator<<(ostream& os, Piece& piece);

    private:
        char symbol;
        string color;
        int player;

    public:
        Piece(int owner);

        int getPlayer();
        void setSymbol(char symbol);

        char toString();;
};

class Pawn : public Piece {
    public:
        Pawn(int owner);
        char toString();
};

class Rook : public Piece {
    public:
        Rook(int owner);
        char toString();
};

class Knight : public Piece {
    public:
        Knight(int owner);
        char toString();
};

class Bishop : public Piece {
    public:
        Bishop(int owner);
        char toString();
};

class Queen : public Piece {
    public:
        Queen(int owner);
        char toString();
};

class King : public Piece {
    public:
        King(int owner);
        char toString();
};

#endif // PIECE_H