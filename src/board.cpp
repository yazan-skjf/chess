#include <iostream>
#include "board.hpp"
#include "loader.hpp"

Board::Board() {
    std::cout << "Board setup complete." << std::endl;
}

void Board::Display() {
    bool isBlackSquare = false;
    for (int r = numRows_-1; r >= 0; r--) {
        std::cout << "|  ";
        for (int c = 0; c < numCols_; c++) {
            std::cout << (isBlackSquare ? "□" : "■") << "  ";
            isBlackSquare = !isBlackSquare;
        }
        std::cout << "|" << std::endl;
        isBlackSquare = !isBlackSquare;
    };
}