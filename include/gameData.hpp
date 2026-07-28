#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

#include "boardState.hpp"

class GameData {
    private:
        std::unordered_map<std::string, BoardState> presets_;
        std::unordered_map<std::string, PieceConfig> pieces_;

    public:
        GameData(std::unordered_map<std::string, BoardState> presets, std::unordered_map<std::string, PieceConfig> pieces) :
            presets_(presets),
            pieces_(pieces)
        {}
};