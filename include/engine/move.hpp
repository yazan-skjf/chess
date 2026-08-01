#pragma once

#include <iostream>

#include "position.hpp"

class Move {
    private:

    public:
        bool movePiece(Board& board, Position posAt, Position posTo);
        bool canMovePiece(Board& board, Position posAt, Position posTo);
};