#pragma once

#include <iostream>
#include <vector>

#include "piece.hpp"

class Board {
    private:
        int numRows_;
        int numCols_;
        std::vector<std::vector<Piece>> squares_;

        static void loadPreset(Board& board);
    public:
        Board();
        Board(int numRows, int numCols, const std::vector<std::vector<Piece>> squares);

        const Piece& getPieceAt(int xPos, int yPos) { return squares_.at(yPos).at(xPos); };

        void Display();

        //helpers
        bool isEmptySquare(int xPos, int yPos) {
            return getPieceAt(xPos, yPos).getName().empty();
        }
        static bool isWhiteSquare(int xPos, int yPos) {
            return (xPos + yPos) % 2 == 0;
        }
};