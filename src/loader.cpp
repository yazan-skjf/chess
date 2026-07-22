#include <fstream>
#include <filesystem>
#include "loader.hpp"
#include "boardState.hpp"
#include "piece.hpp"

using json = nlohmann::json;

Loader::Loader(const std::string& path) {
    std::vector<std::filesystem::path> files = Loader::getFilesInDir(path);
    for (const auto& file: files) {
        if (std::filesystem::is_directory(file))
            continue;

        std::cout << "Attempting file: " << file.string() << std::endl;
        if (file.extension() == ".json") {
            data.push_back(Loader::parseBoardStateJson(Loader::decodeJson(file.string())));
        } else {
            std::cout << "Unsupported file extension: " << file.string() << std::endl;
        }
    }
}

// lol Loader::loadPresets() {

// }

Board Loader::createBoard(const std::string& presetName) {
    Board board;

    for (const auto& state: data) {
        //iterate through each state and fuse them into one board
        
    }

    return board;
}

json Loader::decodeJson(const std::string& path) {
    std::ifstream file(path);

    json data;
    file >> data;

    return data;
}

BoardState Loader::parseBoardStateJson(const json& data) { // parse one file into a boardstate and return it

    BoardState state;

    if (data.contains("presets")) { //parse presets
        int numRows = data["presets"]["numRows"];
        int numCols = data["presets"]["numCols"];
        std::vector<std::vector<std::string>> squares;

        for (const auto& row: data["presets"]["data"]) {
            squares.push_back(row);
        }

        state.setRows(numRows);
        state.setCols(numCols);
        state.setSquares(squares);
    }

    if (data.contains("pieces")) { //parse pieces
        for (auto& [pieceName, pieceData] : data["pieces"].items())
        {
            PieceConfig pieceConf;
            for (auto& [property,value] : pieceData.items()) {
                std::cout << property << " = " << pieceData[property] << ", ";
            }
            std::cout << std::endl;
        }
    }
    
    return state;
}