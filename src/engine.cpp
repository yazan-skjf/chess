#include <iostream>
#include "board.hpp"
#include "move.hpp"
#include "piece.hpp"
#include "loader.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;

    auto pieces = Loader::load("data/pieces.json");
    auto presets = Loader::load("data/presets.json");

    
    Board board;
    board.Display();

    for (auto& [i, v] : pieces.items())
    {
        std::cout << "Loading " << i << ": ";

        for (auto& [i2,v2] : v.items()) {
            std::cout << i2 << " = " << v[i2] << ", ";
        }
        std::cout << std::endl;
    }

    return 0;
};