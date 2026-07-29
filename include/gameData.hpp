#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "boardState.hpp"

class PieceData {
    private:
        std::string name_;
        int id_;

    public:
        PieceData(std::string name, int id) :
            name_(std::move(name)),
            id_(id)
        {}
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
};