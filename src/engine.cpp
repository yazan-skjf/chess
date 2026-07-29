#include <iostream>
#include "board.hpp"
#include "move.hpp"
#include "piece.hpp"
#include "loader.hpp"
#include "gameInstance.hpp"
#include "gameData.hpp"


int main() {
    std::cout << "Hello, World!" << std::endl;

    std::cout << "Creating loader..." << std::endl;
    Loader loader;
    loader.setPath("data");

    std::cout << "Loading files..." << std::endl;
    GameData gameData = loader.loadGameData();

    std::cout << "Displaying game data:\n" << gameData << std::endl;

    // std::cout << "Creating game instance..." << std::endl;
    // GameInstance instance;
    // std::cout << "Success" << std::endl;

    std::cout << "End of program";

    return 0;
};