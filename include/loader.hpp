#pragma once

#include <fstream>
#include <iostream>
#include <string>

#include "boardState.hpp"
#include "board.hpp"
#include <nlohmann/json.hpp>

class Loader {
    private:
        std::vector<BoardState> data_;

        static BoardState parseBoardStateJson(const nlohmann::json& data);

        //file decoders
        static nlohmann::json decodeJson(const std::string& path);

    public:
        Loader(const std::string& path);
        Board createBoard(const std::string& presetName);

        std::vector<std::vector<std::string>> loadPresets();
        std::vector<std::vector<std::string>> loadPieces();

        //helpers
        static std::string getFileExtension(const std::string& path) { return std::filesystem::path(path).extension().string(); }
        static std::vector<std::filesystem::path> getFilesInDir(const std::string& path) {
            std::vector<std::filesystem::path> files;
            for (const auto & entry : std::filesystem::directory_iterator(path)) {
                files.push_back(entry.path());
            }
            return files;
        }
};