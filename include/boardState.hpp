#pragma once

#include <iostream>
#include <vector>
#include <string>

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
        int numRows_;
        int numCols_;
        vector<vector<string>> squares_;
        vector<vector<PieceConfig>> allPieces_;
    public:
        BoardState() :
            numRows_(0),
            numCols_(0),
            squares_(),
            allPieces_()
        {}
        BoardState(int numRows, int numCols, vector<vector<string>> squares) :
            numRows_(numRows),
            numCols_(numCols),
            squares_(squares)
        {}
        int getRows() { return numRows_; }
        int getCols() { return numCols_; }
        void setRows(int n) { numRows_ = n; }
        void setCols(int n) { numCols_ = n; }
        vector<vector<string>>& getSquares() { return squares_; }
        void setSquares(vector<vector<string>>& squares) { squares_ = squares; }
};