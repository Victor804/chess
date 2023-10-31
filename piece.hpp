#include "const.hpp"
#include <iostream>
#include <ostream>

#pragma once

/*
TYPES OF PIECES:
    - Pawn   :  0
    - Rook   :  1
    - Knight :  2
    - Bishop :  3
    - Queen  :  4
    - King   :  5
*/

class Piece {
public:
    Piece();
    Piece(int x, int y, COLOR color);
    ~Piece();
    int getX() const;
    int getY() const;
    int getColor() const;
    void setX(int x);
    void setY(int y);
    void setColor(COLOR color);
    virtual int getType() const = 0;

    virtual bool isValid(int x, int y){ return false;};
    virtual bool isMoved(){ return false;};
    virtual bool canBePromoted(){ return false;};


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
    int getType() const { return 0;};
    bool isValid(int x, int y);
    bool isMoved();
    bool canBePromoted();

private:
    bool moved;
};

class Rook : public Piece {
public:
    Rook();
    Rook(int x, int y, COLOR color);
    ~Rook();
    int getType() const { return 1;};
    bool isValid(int x, int y);
    bool isMoved();

private:
    bool moved;
};

class Knight : public Piece {
public:
    Knight();
    Knight(int x, int y, COLOR color);
    ~Knight();
    int getType() const { return 2;};
    bool isValid(int x, int y);

};

class Bishop : public Piece {
public:
    Bishop();
    Bishop(int x, int y, COLOR color);
    ~Bishop();
    int getType() const { return 3;};
    bool isValid(int x, int y);

};  

class Queen : public Piece {
public:
    Queen();
    Queen(int x, int y, COLOR color);
    ~Queen();
    int getType() const { return 4;};
    bool isValid(int x, int y);

};

class King : public Piece {
public:
    King();
    King(int x, int y, COLOR color);
    ~King();
    int getType() const { return 5;};
    bool isValid(int x, int y);
    bool isMoved();

private:
    bool moved; 
};  