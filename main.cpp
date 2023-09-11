#include <iostream>
#include "piece.hpp"
#include "board.hpp"
#include "player.hpp"

int main() { 
    Board board;
    Player player1(WHITE);
    Player player2(BLACK);

    board.initBoard();
    board.printBoard();
    
    return 0;
}