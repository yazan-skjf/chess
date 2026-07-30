#include <iostream>

#include "piece.hpp"

Piece::Piece() = default;
Piece::Piece(std::string name, int xPos, int yPos, std::string color, std::string icon) :
    name_(name),
    xPos_(xPos),
    yPos_(yPos),
    color_(color),
    icon_(icon)
{};