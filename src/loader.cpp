#include <fstream>
#include <filesystem>
#include "loader.hpp"
#include "boardState.hpp"
#include "piece.hpp"

using json = nlohmann::json;

GameData Loader::loadGameData() {
    std::cout << "Attempting file: data/vanilla.json" << std::endl;
    return parseGameDataJson("data/vanilla.json");
}

Board Loader::createBoard(const std::string& presetName) {
    
}

json Loader::decodeJson(const std::string& path) const {
    std::ifstream file(path);

    json data;
    file >> data;
    
    std::cout << "Successfully decoded: " << path << std::endl;
    return data;
}

GameData Loader::parseGameDataJson(const std::string& path) const {
    const json& data = decodeJson(path);

    std::unordered_map<std::string, PresetData> presets;
    std::unordered_map<std::string, PieceData> pieces;

    if (data.contains("presets")) { //parse presets

        for (auto& [presetName, presetData] : data["presets"].items()) {
            std::vector<std::vector<std::string>> layout;
            for (const auto& row: presetData["data"]) {
                std::cout << row << std::endl;
                layout.push_back(row);
            }
            presets.emplace(presetName, PresetData(presetName, presetData["numRows"], presetData["numCols"], layout));
            std::cout << "Loaded preset: " << presetName << std::endl;
        }
    }

    if (data.contains("pieces")) { //parse pieces
        for (auto& [pieceName, pieceData] : data["pieces"].items())
        {
            pieces.emplace(pieceName, PieceData(pieceName, pieceData["id"]));

            std::cout << "Loading pieces: " << std::endl;
            for (auto& [property,value] : pieceData.items()) {
                std::cout << property << " = " << pieceData[property] << ", ";
            }
            std::cout << std::endl;
        }
    }
    
    return GameData(presets, pieces);
}