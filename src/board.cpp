#include <iostream>
#include "board.hpp"

Board::Board() {
    numRows = 8;
    numCols = 8;
    std::cout << "Board setup complete." << std::endl;
}

void Board::Display() {
    bool isBlackSquare = false;
    for (int r = numRows-1; r >= 0; r--) {
        std::cout << "|  ";
        for (int c = 0; c < numCols; c++) {
            std::cout << (isBlackSquare ? "□" : "■") << "  ";
            isBlackSquare = !isBlackSquare;
        }
        std::cout << "|" << std::endl;
        isBlackSquare = !isBlackSquare;
    };
}