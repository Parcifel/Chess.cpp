#include "coordinate.h"

#include <string>
#include <vector>

using namespace std;

bool Coordinate::isValidIndex(int index) {
    return index >= 0 && index <= 7;
}

bool Coordinate::isValidX(int x) {
    return isValidIndex(x);
}
bool Coordinate::isValidY(int y) {
    return isValidIndex(y);
}
bool Coordinate::isValidCoordinate(int x, int y) {
    return isValidX(x) && isValidY(y);
}

bool Coordinate::isValidRank(int rank) {
    return rank >= 1 && rank <= 8;
}
bool Coordinate::isValidFile(char file) {
    return file >= 'a' && file <= 'h';
}
bool Coordinate::isValidTile(string tile) {
    return tile.length() == 2 && isValidFile(tile[0]) && isValidRank(tile[1] - '0');
}      

Coordinate::Coordinate(int x, int y) {
    setCoordinate(x, y);
}

int Coordinate::getX() {
    return this->x_index;
}
int Coordinate::getY() {
    return this->y_index;
}
void Coordinate::setX(int x) {
    if (isValidX(x)) {
        this->x_index = x;
    }
}
void Coordinate::setY(int y) {
    if (isValidY(y)) {
        this->y_index = y;
    }
}
void Coordinate::setCoordinate(int x, int y) {
    if (isValidCoordinate(x, y)) {
        this->x_index = x;
        this->y_index = y;
    }
}

int Coordinate::getRank() {
    return this->y_index + 1;
}
char Coordinate::getFile() {
    return this->x_index + 'a';
}
void Coordinate::setRank(int rank) {
    if (isValidRank(rank)) {
        this->y_index = rank - 1;
    }
}
void Coordinate::setFile(char file) {
    if (isValidFile(file)) {
        this->x_index = file - 'a';
    }
}
void Coordinate::setTile(string tile) {
    if (isValidTile(tile)) {
        setRank(tile[0] - '0');
        setFile(tile[1]);
    }
}

vector<int> Coordinate::getCoordinate() {
    return {this->x_index, this->y_index};
}
string Coordinate::getTile() {
    return to_string(getRank()) + string(1, getFile());
}