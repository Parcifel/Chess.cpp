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

Coordinate::Coordinate() {
    x_index = -1;
    y_index = -1;
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

void Coordinate::reset() {
    /**
     * This function hard resets the coordinate to an invalid state.
    */
    this->x_index = -1;
    this->y_index = -1;
}

vector<int> Coordinate::getCoordinate() {
    return {this->x_index, this->y_index};
}
string Coordinate::getTile() {
    return to_string(getRank()) + string(1, getFile());
}

bool Coordinate::isValid() {
    return isValidCoordinate(this->x_index, this->y_index);
}

/* Equals */
bool Coordinate::operator==(Coordinate& other) {
    return this->x_index == other.getX() && this->y_index == other.getY();
}
bool Coordinate::operator==(string tile) {
    return this->getTile() == tile;
}
bool Coordinate::operator==(int coordinate[2]) {
    return this->x_index == coordinate[0] && this->y_index == coordinate[1];
}

/* Not Equals */
bool Coordinate::operator!=(Coordinate& other) {
    return this->x_index != other.getX() && this->y_index != other.getY();
}
bool Coordinate::operator!=(string tile) {
    return this->getTile() != tile;
}
bool Coordinate::operator!=(int coordinate[2]) {
    return this->x_index != coordinate[0] && this->y_index != coordinate[1];
}

/* Less Than */
bool Coordinate::operator>(Coordinate& other) {
    return this->x_index > other.getX() && this->y_index > other.getY();
}
bool Coordinate::operator>(string tile) {
    Coordinate other;
    other.setTile(tile);
    return this->x_index > other.getX() && this->y_index > other.getY();
}
bool Coordinate::operator>(int coordinate[2]) {
    return this->x_index > coordinate[0] && this->y_index > coordinate[1];
}

/* Greater Than */
bool Coordinate::operator<(Coordinate& other) {
    return this->x_index < other.getX() && this->y_index < other.getY();
}
bool Coordinate::operator<(string tile) {
    Coordinate other;
    other.setTile(tile);
    return this->x_index < other.getX() && this->y_index < other.getY();
}
bool Coordinate::operator<(int coordinate[2]) {
    return this->x_index < coordinate[0] && this->y_index < coordinate[1];
}

/* Less Than or Equal To */
bool Coordinate::operator<=(Coordinate& other) {
    return this->x_index <= other.getX() && this->y_index <= other.getY();
}
bool Coordinate::operator<=(string tile) {
    Coordinate other;
    other.setTile(tile);
    return this->x_index <= other.getX() && this->y_index <= other.getY();
}
bool Coordinate::operator<=(int coordinate[2]) {
    return this->x_index <= coordinate[0] && this->y_index <= coordinate[1];
}

/* Greater Than or Equal To */
bool Coordinate::operator>=(Coordinate& other) {
    return this->x_index >= other.getX() && this->y_index >= other.getY();
}
bool Coordinate::operator>=(string tile) {
    Coordinate other;
    other.setTile(tile);
    return this->x_index >= other.getX() && this->y_index >= other.getY();
}
bool Coordinate::operator>=(int coordinate[2]) {
    return this->x_index >= coordinate[0] && this->y_index >= coordinate[1];
}
