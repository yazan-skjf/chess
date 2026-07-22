#include <iostream>
#include "board.hpp"
#include "move.hpp"
#include "piece.hpp"
#include "loader.hpp"
#include "gameInstance.hpp"


int main() {
    std::cout << "Hello, World!" << std::endl;

    std::cout << "Creating game instance..." << std::endl;
    GameInstance instance;
    std::cout << "Success" << std::endl;

    return 0;
};