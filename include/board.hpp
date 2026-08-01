#pragma once

#include <iostream>
#include <vector>

#include "piece.hpp"
#include "position.hpp"

class Board {
    private:
        int numRows_;
        int numCols_;
        std::vector<std::vector<Piece>> squares_;

        static void loadPreset(Board& board);
    public:
        Board();
        Board(int numRows, int numCols, const std::vector<std::vector<Piece>> squares);

        const Piece& getPieceAt(Position pos) { return squares_.at(pos.y).at(pos.x); };

        void Display();

        //helpers
        bool isEmptySquare(Position pos) {
            return getPieceAt(pos).getName().empty();
        }
};