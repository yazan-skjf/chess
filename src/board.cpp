#include <iostream>
#include "board.hpp"
#include "loader.hpp"

Board::Board() {}

Board::Board(int numRows, int numCols, const std::vector<std::vector<Piece>> squares) :
    numRows_(numRows),
    numCols_(numCols),
    squares_(std::move(squares))
{}

void Board::Display() {
    for (int r = numRows_-1; r >= 0; r--) {
        std::cout << "|  ";
        for (int c = 0; c < numCols_; c++) {
            if (isEmptySquare(c, r)) {
                if (isWhiteSquare(c, r)) {
                    std::cout << "■  ";
                } else {
                    std::cout << "□  ";
                }
            } else {
                std::cout << getPieceAt(c, r).getIcon() << "  ";
            }
        }
        std::cout << "|" << std::endl;
    };
}