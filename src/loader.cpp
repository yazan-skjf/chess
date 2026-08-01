#include <fstream>
#include <filesystem>
#include <algorithm>

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

Board Loader::createBoard(GameData& gameData, const std::string& presetName) {
    const PresetData& preset = gameData.getPreset(presetName);

    std::vector<std::vector<Piece>> squares(preset.getNumRows());
    int y = 0;
    for (const auto& row: preset.getLayout()) {
        int x = 0;
        for (const auto& squareName: row) { //squareName = "black.rook"
            if (squareName.empty()) {
                squares.at(y).push_back(Piece());
                continue;
            }
            auto [color, pieceName] = splitPieceName(squareName);
            const PieceData& piece = gameData.getPiece(pieceName);
            squares.at(y).push_back(Piece(pieceName, Position{x, y}, color, piece.getIcon(color)));
            x++;
        }
        y++;
    }

    return Board(preset.getNumRows(), preset.getNumCols(), squares);
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
            std::reverse(layout.begin(), layout.end());
            gameData.addPreset(presetName, PresetData(presetName, presetData["numRows"], presetData["numCols"], std::move(layout)));
        }
    }

    if (data.contains("pieces")) { //parse pieces
        for (auto& [pieceName, pieceData] : data["pieces"].items()) {
            std::unordered_map<std::string, std::string> icons;
            for (auto& [colorName, colorIcon] : pieceData["colors"].items()) {
                icons.insert_or_assign(std::move(colorName), std::move(colorIcon));
            }
            gameData.addPiece(pieceName, PieceData(pieceName, pieceData["id"], icons));
        }
    }
}