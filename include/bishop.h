#pragma once

#include "../include/piece.h"

#include <cmath> 

using namespace std;

class Bishop : public Piece {
public:
    
    Bishop(Color color, int x, int y, Board* board) 
        : Piece(color, x, y, PieceType::Bishop, board, 15, 10, 65) {}

    // implements both move and attack
    bool move(int x1, int y1, int x2, int y2) override;
    
};

