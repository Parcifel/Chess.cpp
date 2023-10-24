#ifndef COORDINATE_H
#define COORDINATE_H

#include <string>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

class Coordinate {
    private:
        int x_index;
        int y_index;

        bool isValidIndex(int index);

        bool isValidX(int x);
        bool isValidY(int y);
        bool isValidCoordinate(int x, int y);

        bool isValidRank(int rank);
        bool isValidFile(char file);
        bool isValidTile(string tile);

    public:
        Coordinate();
        Coordinate(int x, int y);

        int getX();
        int getY();
        void setX(int x);
        void setY(int y);
        void setCoordinate(int x, int y);
        
        int getRank();
        char getFile();
        void setRank(int rank);
        void setFile(char file);
        void setTile(string tile);

        void reset();

        vector<int> getCoordinate();
        string getTile();

        bool isValid();

        bool operator==(Coordinate& other);
        bool operator==(string tile);
        bool operator==(int coordinate[2]);

        bool operator!=(Coordinate& other);
        bool operator!=(string tile);
        bool operator!=(int coordinate[2]);

        bool operator<(Coordinate& other);
        bool operator<(string tile);
        bool operator<(int coordinate[2]);

        bool operator>(Coordinate& other);
        bool operator>(string tile);
        bool operator>(int coordinate[2]);

        bool operator<=(Coordinate& other);
        bool operator<=(string tile);
        bool operator<=(int coordinate[2]);

        bool operator>=(Coordinate& other);
        bool operator>=(string tile);
        bool operator>=(int coordinate[2]);

};

#endif // COORDINATE_H

