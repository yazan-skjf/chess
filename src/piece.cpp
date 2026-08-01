#include <iostream>

#include "piece.hpp"
#include "position.hpp"

Piece::Piece() = default;
Piece::Piece(std::string name, Position position, std::string color, std::string icon) :
    name_(name),
    position_(position),
    color_(color),
    icon_(icon)
{};