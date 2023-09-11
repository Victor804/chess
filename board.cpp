#include "board.hpp"
#include "piece.hpp"
#include <iostream>
#include <vector>

Board::Board() {
    board = std::vector<Piece>(32);
}

Board::~Board() {
}

void Board::addPiece(Piece piece) {
    board.push_back(piece);
}

bool Board::delPiece(Piece piece) {
    for (int i = 0; i < board.size(); i++) {
        if (board[i].getX() == piece.getX() && board[i].getY() == piece.getY()) {
            board.erase(board.begin() + i);
            return true;
        }
    }
    return false;
}

bool Board::delPiece(int x, int y) {
    for (int i = 0; i < board.size(); i++) {
        if (board[i].getX() == x && board[i].getY() == y) {
            board.erase(board.begin() + i);
            return true;
        }
    }
    return false;
}

void Board::movePiece(Piece piece, int x, int y) {
    for (int i = 0; i < board.size(); i++) {
        if (board[i].getX() == piece.getX() && board[i].getY() == piece.getY()) {
            board[i].setX(x);
            board[i].setY(y);
        }
    }
}

bool Board::inBoard(int x, int y) {
    if (x < 0 || x > 7 || y < 0 || y > 7) {
        return false;
    }
    return true;
}

bool Board::isOccupied(int x, int y) {
    for (int i = 0; i < board.size(); i++) {
        if (board[i].getX() == x && board[i].getY() == y) {
            return true;
        }
    }
    return false;
}



void Board::initBoard(){
    this->addPiece(Rook(0, 0, WHITE));
    this->addPiece(Knight(0, 1, WHITE));
    this->addPiece(Bishop(0, 2, WHITE));
    this->addPiece(Queen(0, 3, WHITE));
    this->addPiece(King(0, 4, WHITE));
    this->addPiece(Bishop(0, 5, WHITE));
    this->addPiece(Knight(0, 6, WHITE));
    this->addPiece(Rook(0, 7, WHITE));

    this->addPiece(Pawn(1, 0, WHITE));
    this->addPiece(Pawn(1, 1, WHITE));
    this->addPiece(Pawn(1, 2, WHITE));
    this->addPiece(Pawn(1, 3, WHITE));
    this->addPiece(Pawn(1, 4, WHITE));
    this->addPiece(Pawn(1, 5, WHITE));
    this->addPiece(Pawn(1, 6, WHITE));
    this->addPiece(Pawn(1, 7, WHITE));


    this->addPiece(Rook(7, 0, BLACK));
    this->addPiece(Knight(7, 1, BLACK));
    this->addPiece(Bishop(7, 2, BLACK));
    this->addPiece(Queen(7, 3, BLACK));
    this->addPiece(King(7, 4, BLACK));
    this->addPiece(Bishop(7, 5, BLACK));
    this->addPiece(Knight(7, 6, BLACK));
    this->addPiece(Rook(7, 7, BLACK));

    this->addPiece(Pawn(6, 0, BLACK));
    this->addPiece(Pawn(6, 1, BLACK));
    this->addPiece(Pawn(6, 2, BLACK));
    this->addPiece(Pawn(6, 3, BLACK));
    this->addPiece(Pawn(6, 4, BLACK));
    this->addPiece(Pawn(6, 5, BLACK));
    this->addPiece(Pawn(6, 6, BLACK));
    this->addPiece(Pawn(6, 7, BLACK));
}

void Board::printBoard(){
    std::cout << this->getPiece(0, 0) << std::endl;
}