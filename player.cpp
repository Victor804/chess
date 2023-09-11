#include "player.hpp"

Player::Player(COLOR color) {
    this->color = color;
}

Player::~Player() {
}

COLOR Player::getColor() {
    return color;
}