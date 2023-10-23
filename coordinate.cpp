#ifndef COORDINATE_CPP
#define COORDINATE_CPP

#include "coordinate.h"

#include <string>
#include <vector>

using namespace std;

Coordinate::Coordinate(int x, int y) {
    setCoordinate(x, y);
}

int Coordinate::getX() {
    return x_index;
}
int Coordinate::getY() {
    return y_index;
}
void Coordinate::setX(int x) {
    if (isValidX(x)) {
        x_index = x;
    }
}
void Coordinate::setY(int y) {
    if (isValidY(y)) {
        y_index = y;
    }
}
void Coordinate::setCoordinate(int x, int y) {
    if (isValidCoordinate(x, y)) {
        x_index = x;
        y_index = y;
    }
}

int Coordinate::getRank() {
    return y_index + 1;
}
char Coordinate::getFile() {
    return x_index + 'a';
}
void Coordinate::setRank(int rank) {
    if (isValidRank(rank)) {
        y_index = rank - 1;
    }
}
void Coordinate::setFile(char file) {
    if (isValidFile(file)) {
        x_index = file - 'a';
    }
}
void Coordinate::setTile(string tile) {
    if (isValidTile(tile)) {
        setRank(tile[0] - '0');
        setFile(tile[1]);
    }
}

vector<int> Coordinate::getCoordinate() {
    return {x_index, y_index};
}
string Coordinate::getTile() {
    return to_string(getRank()) + string(1, getFile());
}

#endif // COORDINATE_CPP