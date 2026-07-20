#pragma once

#include <iostream>
#include <vector>
#include "piece.hpp"

class Board {
    private:
        int numRows;
        int numCols;
        std::vector<std::vector<Piece>> squares;
    public:
        Board();
        void Display();
};