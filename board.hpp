#include "piece.hpp"
#include <vector>

#pragma once

class Board {
    public:
        Board();
        ~Board();
        void addPiece(Piece* piece);
        bool delPiece(Piece* piece);
        bool delPiece(int x, int y);
        void movePiece(Piece* piece, int x, int y);
        bool inBoard(int x, int y);
        bool isOccupied(int x, int y);
        bool validMove(Piece piece, int x, int y);
        void printBoard();
        bool isCheck(COLOR color);
        bool isCheckMate(COLOR color);
        Piece* getPiece(int x, int y);
        bool isStaleMate(COLOR color);
        std::vector<Piece> getBoard();
        void initBoard();

    private:
        std::vector<Piece*> board;
};