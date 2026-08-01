#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class PieceData {
    private:
        std::string name_;
        int id_;
        std::unordered_map<std::string, std::string> icons_;

    public:
        PieceData(std::string name, int id, std::unordered_map<std::string, std::string> icons) :
            name_(std::move(name)),
            id_(id),
            icons_(std::move(icons))
        {}

        const std::string& getName() const { return name_; };
        int getId() const { return id_; };
        const std::string& getIcon(const std::string& color) const { return icons_.at(color); };
};

class PresetData {
    private:
        std::string name_;
        int numRows_;
        int numCols_;
        std::vector<std::vector<std::string>> layout_;

    public:
        PresetData(std::string name, int numRows, int numCols, std::vector<std::vector<std::string>> layout) :
            name_(std::move(name)),
            numRows_(numRows),
            numCols_(numCols),
            layout_(std::move(layout))
        {}

        const std::string& getName() const { return name_; };
        int getNumRows() const { return numRows_; };
        int getNumCols() const { return numCols_; };
        const std::vector<std::vector<std::string>>& getLayout() const { return layout_; };
};

class GameData {
    private:
        std::unordered_map<std::string, PresetData> presets_;
        std::unordered_map<std::string, PieceData> pieces_;

    public:
        GameData() {};
        GameData(std::unordered_map<std::string, PresetData> presets, std::unordered_map<std::string, PieceData> pieces) :
            presets_(std::move(presets)),
            pieces_(std::move(pieces))
        {}

        friend std::ostream& operator<<(std::ostream& os, const GameData& gameData) {

            os << "Presets:\n";
            for (auto& [presetName,rows] : gameData.presets_) {
                os << presetName << ", ";
            }

            os << "\nPieces:\n";
            for (auto& [pieceName,data] : gameData.pieces_) {
                os << pieceName << ", ";
            }
            
            os << "\n";

            return os;
        }

        void addPreset(std::string name, PresetData preset) {
            presets_.insert_or_assign(std::move(name), std::move(preset));
        }
        void addPiece(std::string name, PieceData piece) {
            pieces_.insert_or_assign(std::move(name), std::move(piece));
        }

        const PresetData& getPreset(const std::string& presetName) { return presets_.at(presetName); };
        const PieceData& getPiece(const std::string& pieceName) { return pieces_.at(pieceName); };


        void printPresets() {
            for (const auto& [name, preset] : presets_)
            {
                std::cout << "Preset: " << name << '\n';
            }
        }
};