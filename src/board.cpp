#include <iostream>

#include "board.hpp"
#include "loader.hpp"
#include "position.hpp"

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
            Position position{c, r};
            if (isEmptySquare(position)) {
                if (Position::isWhiteSquare(position)) {
                    std::cout << "■  ";
                } else {
                    std::cout << "□  ";
                }
            } else {
                std::cout << getPieceAt(position).getIcon() << "  ";
            }
        }
        std::cout << "|" << std::endl;
    };
}