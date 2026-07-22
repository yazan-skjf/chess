#pragma once

#include <iostream>
#include <vector>
#include "piece.hpp"

using std::vector;
using string = std::string;

class PieceConfig {
    private:
        
    public:
        PieceConfig() {
            std::cout << "created";
        }
};

class BoardState {
    private:
        int numRows;
        int numCols;
        vector<vector<string>> squares;
        vector<vector<PieceConfig>> allPieces;
    public:
        BoardState() :
            numRows(0),
            numCols(0),
            squares(),
            allPieces()
        {}
        BoardState(int numRows, int numCols, vector<vector<string>> squares) :
            numRows(numRows),
            numCols(numCols),
            squares(squares)
        {}
        int getRows() { return numRows; }
        int getCols() { return numCols; }
        void setRows(int n) { numRows = n; }
        void setCols(int n) { numCols = n; }
        vector<vector<string>>& getSquares() { return squares; }
        void setSquares(vector<vector<string>>& s) { squares = s; }
};