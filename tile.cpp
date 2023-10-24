#include "tile.h"
#include "panel.h"

Tile::Tile(Piece* occupant) {
    this->occupant = occupant;
}

void Tile::setOccupant(Piece* occupant) {
    this->occupant = occupant;
}

Piece* Tile::getOccupant() {
    return this->occupant;
}

bool Tile::isOccupied() {
    return this->occupant != nullptr;
}

char Tile::toString() {
    if (this->isOccupied()) {
        return this->occupant->toString();
    } else {
        return '.';
    }
}

