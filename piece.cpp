#include "piece.h"
#include "constants.h"

#include <iostream>
#include <string>
#include <string_view>

/*===============================================================================================*/
/* PIECE */
ostream& operator<<(ostream& os, Piece& piece) {
    os << piece.toString();
    return os;
}

Piece::Piece(int owner) {
    this->player = owner;
    this->color = (owner == WHITE) ? "white" : "black";
}

int Piece::getPlayer() {
    return this->player;
}

void Piece::setSymbol(char symbol) {
    this->symbol = symbol;
}

char Piece::toString() {
    return (this->symbol==' ') ? '.' : this->symbol;
}




/*===============================================================================================*/
/* PAWN */
Pawn::Pawn(int owner) : Piece(owner) {
    this->setSymbol( (this->getPlayer() == WHITE) ? 'P' : 'p' );
}
/*===============================================================================================*/
/* ROOK */
Rook::Rook(int owner) : Piece(owner) {
    this->setSymbol( (this->getPlayer() == WHITE) ? 'R' : 'r' );
}
/*===============================================================================================*/
/* KNIGHT */
Knight::Knight(int owner) : Piece(owner) {
    this->setSymbol( (this->getPlayer() == WHITE) ? 'N' : 'n' );
}
/*===============================================================================================*/
/* BISHOP */
Bishop::Bishop(int owner) : Piece(owner) {
    this->setSymbol( (this->getPlayer() == WHITE) ? 'B' : 'b' );
}
/*===============================================================================================*/
/* QUEEN */
Queen::Queen(int owner) : Piece(owner) {
    this->setSymbol( (this->getPlayer() == WHITE) ? 'Q' : 'q' );
}
/*===============================================================================================*/
/* KING */
King::King(int owner) : Piece(owner) {
    this->setSymbol( (this->getPlayer() == WHITE) ? 'K' : 'k' );
}