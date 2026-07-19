#include <iostream>

class Board {
    private:
        int numRows;
        int numCols;
    public:
        Board();
        Board(int numRows, int numCols);
        void Display();
};