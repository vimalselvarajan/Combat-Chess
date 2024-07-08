#pragma once

#include "../include/piece.h"

class King : public Piece {
public:
    King(Color color, int x, int y, Board* board) 
    : Piece(color, x, y, PieceType::King, board, 1, 100, 95), hasMoved(false) {}

    bool move(int x1, int y1, int x2, int y2) override;
    bool isMoveValid(int x1, int y1, int x2, int y2);
    bool hasMoved; // Track if the King has moved

    bool hasMovedBefore() const; // Check if the King has moved before
};