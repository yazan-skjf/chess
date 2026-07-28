#pragma once

#include <iostream>
#include <string>

#include "loader.hpp"
#include "board.hpp"

class GameInstance {
    private:
        Loader loader_;
        Board board_;
        
        BoardState preset_;
        std::unordered_map<std::string, PieceConfig> pieces_;

    public:
        GameInstance() :
            loader_("data"),
           board_(loader_.createBoard("standard"))
        {}
};