#include "tile.h"

Tile::Tile() {
    this->occupant = nullptr;
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

string Tile::toString() {
    if (this->isOccupied()) {
        return this->occupant->toString();
    } else {
        return ".";
    }
}

