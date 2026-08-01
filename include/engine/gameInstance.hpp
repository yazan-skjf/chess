#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

#include "loader.hpp"
#include "board.hpp"

class GameInstance {
    private:
        std::string presetName_;

        Board board_;

    public:
        GameInstance(GameData& gameData, const std::string& presetName) : 
            presetName_(presetName),
            board_(Loader::createBoard(gameData, presetName))
        {}

        void Display() { board_.Display(); }
};