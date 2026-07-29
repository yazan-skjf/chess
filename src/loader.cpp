#include <fstream>
#include <filesystem>
#include "loader.hpp"
#include "boardState.hpp"
#include "piece.hpp"

using json = nlohmann::json;

GameData Loader::loadGameData() {
    GameData gameData;

    std::vector<std::filesystem::path> files = Loader::getFilesInDir(path_);
    for (const auto& file: files) {
        if (std::filesystem::is_directory(file))
            continue;

        std::cout << "Attempting file: " << file.string() << std::endl;
        if (file.extension() == ".json") {
            parseGameDataJson(file.string(), gameData);
        } else {
            std::cout << "Unsupported file extension: " << file.string() << std::endl;
        }
    }
    return gameData;
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

void Loader::parseGameDataJson(const std::string& path, GameData& gameData) const {
    const json& data = decodeJson(path);

    if (data.contains("presets")) { //parse presets

        for (auto& [presetName, presetData] : data["presets"].items()) {
            std::vector<std::vector<std::string>> layout;
            for (const auto& row: presetData["data"]) {
                layout.push_back(row);
            }
            gameData.addPreset(presetName, PresetData(presetName, presetData["numRows"], presetData["numCols"], std::move(layout)));
        }
    }

    if (data.contains("pieces")) { //parse pieces
        for (auto& [pieceName, pieceData] : data["pieces"].items()) {
            gameData.addPiece(pieceName, PieceData(pieceName, pieceData["id"]));
        }
    }
}