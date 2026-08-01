#pragma once

struct Position {
    int x; //column
    int y; //row

    static bool isWhiteSquare(Position pos) {
        return (pos.x + pos.y) % 2 == 0;
    }
};