#pragma once

#include "../include/piece.h"
#include "../include/Board.h"
#include "../include/king.h"

#include <vector>

class Rook : public Piece {
private:
    King* king;
public:
    Rook(Color color, int x, int y, Board* board, King* king) 
        : Piece(color, x, y, PieceType::Rook, board, 40, 20, 75), hasMoved(false), king(king) {}

    bool move(int x1, int y1, int x2, int y2) override;
    bool canCastle(int x1, int y1, int x2, int y2);

    bool hasMoved; 
};