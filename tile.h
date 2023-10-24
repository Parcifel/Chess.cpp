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
        Tile(Piece* occupant);

        void setOccupant(Piece* occupant);
        Piece* getOccupant();
        bool isOccupied();

        char toString();

};

#endif // TILE_H