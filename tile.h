#ifndef TILE_H
#define TILE_H

#include "piece.h"

#include <string>

using namespace std;

class Tile {
    private:
        Piece* occupant=nullptr;

    public:
        Tile() = default;

        void setOccupant(Piece* occupant);
        Piece* getOccupant();
        bool isOccupied();

        string toString();

};

#endif // TILE_H