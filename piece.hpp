#include "const.hpp"
#include <iostream>

#pragma once

class Piece {
public:
    Piece();
    Piece(int x, int y, COLOR color);
    ~Piece();
    int getX();
    int getY();
    int getColor();
    void setX(int x);
    void setY(int y);
    void setColor(COLOR color);
    friend std::ostream& operator<<(std::ostream& flux, const Pawn& p);

protected:
    int x;
    int y;
    COLOR color;
};

class Pawn : public Piece {
public:
    Pawn();
    Pawn(int x, int y, COLOR color);
    ~Pawn();
    bool isValid(int x, int y);
    bool isMoved();
    bool canBePromoted();
    friend std::ostream& operator<<(std::ostream& flux, const Pawn& p);

private:
    const char* name = "PAWN";
    bool moved;
};

class Rook : public Piece {
public:
    Rook();
    Rook(int x, int y, COLOR color);
    ~Rook();
    bool isValid(int x, int y);
    bool isMoved();
    friend std::ostream& operator<<(std::ostream& flux, const Rook& r);

private:
    const char* name = "ROOK";
    bool moved;
};

class Knight : public Piece {
public:
    Knight();
    Knight(int x, int y, COLOR color);
    ~Knight();
    bool isValid(int x, int y);
    friend std::ostream& operator<<(std::ostream& flux, const Knight& k);

private:
    const char* name = "KNIGHT";
};

class Bishop : public Piece {
public:
    Bishop();
    Bishop(int x, int y, COLOR color);
    ~Bishop();
    bool isValid(int x, int y);
    friend std::ostream& operator<<(std::ostream& flux, const Bishop& b);


private:
    const char* name = "BISHOP";
};  

class Queen : public Piece {
public:
    Queen();
    Queen(int x, int y, COLOR color);
    ~Queen();
    bool isValid(int x, int y);
    friend std::ostream& operator<<(std::ostream& flux, const Queen& q);

private:
    const char* name = "QUEEN";
};

class King : public Piece {
public:
    King();
    King(int x, int y, COLOR color);
    ~King();
    bool isValid(int x, int y);
    bool isMoved();
    friend std::ostream& operator<<(std::ostream& flux, const King& k);

private:
    bool moved; 
    const char* name = "KING";
};  