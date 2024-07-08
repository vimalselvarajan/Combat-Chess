#pragma once

#include "../include/piece.h"

class Knight : public Piece {
public:
    Knight(Color color, int x, int y, Board* board) 
        : Piece(color, x, y, PieceType::Knight, board, 25, 15, 70) {}

    bool move(int x1, int y1, int x2, int y2) override;
};


