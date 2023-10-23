#include <string>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

class Coordinate {
    private:
        int x_index;
        int y_index;

        bool isValidIndex(int index) {
            return index >= 0 && index <= 7;
        }

        bool isValidX(int x) {
            return isValidIndex(x);
        }
        bool isValidY(int y) {
            return isValidIndex(y);
        }
        bool isValidCoordinate(int x, int y) {
            return isValidX(x) && isValidY(y);
        }

        bool isValidRank(int rank) {
            return rank >= 1 && rank <= 8;
        }
        bool isValidFile(char file) {
            return file >= 'a' && file <= 'h';
        }
        bool isValidTile(string tile) {
            return tile.length() == 2 && isValidFile(tile[0]) && isValidRank(tile[1] - '0');
        }       

    public:
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

        vector<int> getCoordinate();
        string getTile();

};

