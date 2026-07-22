#pragma once

#include <iostream>
#include "loader.hpp"
#include "board.hpp"

class GameInstance {
    private:
        Loader loader(const std::string& path);
        Board board;

        // std::unordered_map<std::string, BoardState> presets;
        // std::unordered_map<std::string, PieceConfig> pieces;

    public:
        GameInstance() {
            Loader loader("data");
            Board board = loader.createBoard("standard");
        };
};