#include <iostream>
#include "piece.hpp"

//Piece definitions
Piece::Piece() {
    x = 0;
    y = 0;
    color = COLOR::WHITE;
}

Piece::Piece(int x, int y, COLOR color) {
    this->x = x;
    this->y = y;
    this->color = color;
}

Piece::~Piece() {
}

int Piece::getX() {
    return x;
}

int Piece::getY() {
    return y;
}

int Piece::getColor() {
    return color;
}

void Piece::setX(int x) {
    this->x = x;
}

void Piece::setY(int y) {
    this->y = y;
}

void Piece::setColor(COLOR color) {
    this->color = color;
}


// Pawn definitions
Pawn::Pawn() {
    moved = false;
}

Pawn::Pawn(int x, int y, COLOR color)
: Piece(x, y, color) {
    moved = false;
}

Pawn::~Pawn() {
}

bool Pawn::isValid(int x, int y) {
    //Prise en passant pas encore implementee !!
    if (this->getColor() == COLOR::WHITE) {
        if (y == this->getY() + 1) {
            if (x == this->getX()) {//Avance d'une case
                return true;
            }
            else if (x == this->getX() + 1 || x == this->getX() - 1) {//Piece de piece
                return true;
            }
        }
        else if (moved == false && y == this->getY() + 2) {
            if (x == this->getX()) {//Avance de deux cases
                return true;
            }
        }
    }
    else if (this->getColor() == COLOR::BLACK) {
        if (y == this->getY() - 1) {
            if (x == this->getX()) {//Avance d'une case
                return true;
            }
            
            else if (x == this->getX() + 1 || x == this->getX() - 1) {//Piece de piece
                return true;
            }
        }

        else if (moved == false && y == this->getY() - 2) {
            if (x == this->getX()) {//Avance de deux cases
                return true;
            }
        }
    }
    return false;
}

bool Pawn::isMoved() {
    return moved;
}

bool Pawn::canBePromoted() {
    if (this->getColor() == COLOR::WHITE) {
        if (this->getY() == 7) {
            return true;
        }
    }
    else if (this->getColor() == COLOR::BLACK) {
        if (this->getY() == 0) {
            return true;
        }
    }
    return false;
}

// Rook definitions
Rook::Rook() {
    moved = false;
}

Rook::Rook(int x, int y, COLOR color)
: Piece(x, y, color) {
    moved = false;
}

Rook::~Rook() {
}

bool Rook::isValid(int x, int y) {
    if (x == this->getX() && y != this->getY()) {
        return true;
    }
    else if (x != this->getX() && y == this->getY()) {
        return true;
    }
    else {
        return false;
    }  
}

bool Rook::isMoved() {
    return moved;
}

// Knight definitions
Knight::Knight() {
}

Knight::Knight(int x, int y, COLOR color)
: Piece(x, y, color) {
}

Knight::~Knight() {
}

bool Knight::isValid(int x, int y) {
    if (x == this->getX() + 1 || x == this->getX() - 1) {
        if (y == this->getY() + 2 || y == this->getY() - 2) {
            return true;
        }
    }
    else if (x == this->getX() + 2 || x == this->getX() - 2) {
        if (y == this->getY() + 1 || y == this->getY() - 1) {
            return true;
        }
    }
    return false;
}

// Bishop definitions
Bishop::Bishop() {
}

Bishop::Bishop(int x, int y, COLOR color)
: Piece(x, y, color) {
}

Bishop::~Bishop() {
}

bool Bishop::isValid(int x, int y) {
    if (x - this->getX() == y - this->getY()) {
        return true;
    }
    else if (x - this->getX() == -(y - this->getY())) {
        return true;
    }
    else {
        return false;
    }
}

// Queen definitions
Queen::Queen() {
}

Queen::Queen(int x, int y, COLOR color)
: Piece(x, y, color) {
}

Queen::~Queen() {
}

bool Queen::isValid(int x, int y) {
    if (x == this->getX() && y != this->getY()) {
        return true;
    }
    else if (x != this->getX() && y == this->getY()) {
        return true;
    }
    else if (x - this->getX() == y - this->getY()) {
        return true;
    }
    else if (x - this->getX() == -(y - this->getY())) {
        return true;
    }
    else {
        return false;
    }
}

// King definitions
King::King() {
    moved = false;
}

King::King(int x, int y, COLOR color)
: Piece(x, y, color) {
    moved = false;
}

King::~King() {
}

bool King::isValid(int x, int y) {
    if (x == this->getX() + 1 || x == this->getX() - 1) {
        if (y == this->getY() + 1 || y == this->getY() - 1) {
            return true;
        }
    }
    else if (x == this->getX()) {
        if (y == this->getY() + 1 || y == this->getY() - 1) {
            return true;
        }
    }
    else if (y == this->getY()) {
        if (x == this->getX() + 1 || x == this->getX() - 1) {
            return true;
        }
    }
    return false;
}

bool King::isMoved() {
    return moved;
}

std::ostream& operator<<(std::ostream& flux, const Pawn& p){
    flux << p.name << "," << p.x << "," << p.y;
    return flux;
}

std::ostream& operator<<(std::ostream& flux, const Rook& r){
    flux << r.name << "," << r.x << "," << r.y;
    return flux;
}

std::ostream& operator<<(std::ostream& flux, const Knight& k){
    flux << k.name << "," << k.x << "," << k.y;
    return flux;
}

std::ostream& operator<<(std::ostream& flux, const Bishop& b){
    flux << b.name << "," << b.x << "," << b.y;
    return flux;
}

std::ostream& operator<<(std::ostream& flux, const Queen& q){
    flux << q.name << "," << q.x << "," << q.y;
    return flux;
}

std::ostream& operator<<(std::ostream& flux, const King& k){
    flux << k.name << "," << k.x << "," << k.y;
    return flux;
}
