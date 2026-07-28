#pragma once

#include <iostream>
#include <vector>

#include "piece.hpp"

class Board {
    private:
        int numRows_;
        int numCols_;
        std::vector<std::vector<Piece>> squares_;
        std::vector<Piece> allPieces_;

        static void loadPreset(Board& board);
    public:
        Board();
        void Display();
};