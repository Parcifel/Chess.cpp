#include "piece.h"

Piece::Piece() {
    this->type = "";
    this->color = "";
}

char Piece::toString() {
    return 'P';
}