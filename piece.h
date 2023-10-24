#ifndef PIECE_H
#define PIECE_H

#include <string>

using namespace std;

class Piece {
    private:
        string type; //?
        string color;

    public:
        Piece();
        char toString();
};

#endif // PIECE_H