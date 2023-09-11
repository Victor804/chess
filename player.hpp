#include <vector>
#include "piece.hpp"

#pragma once

struct MOVE {
    int x;
    int y;
    int x2;
    int y2;
};



class Player {
    public:
        Player(COLOR color);
        ~Player();
        void setColor(COLOR color);
        COLOR getColor();
    private:
        COLOR color;

};