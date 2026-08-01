#pragma once

#include <iostream>
#include <string>

#include "position.hpp"

class Piece {
    private:
        std::string name_;
        Position position_;
        std::string color_;
        std::string icon_;


    public:
        Piece();
        Piece(std::string name, Position position, std::string color, std::string icon);

        const std::string& getName() const { return name_; };
        const std::string& getIcon() const { return icon_; };
};