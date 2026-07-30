#pragma once

#include <fstream>
#include <iostream>
#include <string>

#include "boardState.hpp"
#include "board.hpp"
#include "gameData.hpp"
#include <nlohmann/json.hpp>

class Loader {
    private:
        std::string path_;

        void parseGameDataJson(const std::string& path, GameData& gameData) const;

        //file decoders
        nlohmann::json decodeJson(const std::string& path) const;

    public:
        Loader() :
            path_("data")
        {}
        void setPath(const std::string& path) { path_ = path; };
        const std::string& getPath() const { return path_; };

        static Board createBoard(GameData& gameData, const std::string& presetName);

        GameData loadGameData();

        //helpers
        static std::string getFileExtension(const std::string& path) { return std::filesystem::path(path).extension().string(); }
        static std::vector<std::filesystem::path> getFilesInDir(const std::string& path) {
            std::vector<std::filesystem::path> files;
            for (const auto & entry : std::filesystem::directory_iterator(path)) {
                files.push_back(entry.path());
            }
            return files;
        }
        static std::pair<std::string, std::string> splitPieceName(const std::string& name) {
            size_t dot = name.find('.');
            if (dot == std::string::npos) {
                throw std::runtime_error("Invalid format: " + name);
            }
            return { name.substr(0, dot), name.substr(dot + 1)};
        }
};