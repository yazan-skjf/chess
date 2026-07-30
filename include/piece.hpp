#pragma once

#include <iostream>
#include <string>

class Piece {
    private:
        std::string name_;
        int xPos_;
        int yPos_;
        std::string color_;
        std::string icon_;


    public:
        Piece();
        Piece(std::string name, int xPos, int yPos, std::string color, std::string icon);

        const std::string& getName() const { return name_; };
        const std::string& getIcon() const { return icon_; };
};