#pragma once

#include "../include/piece.h"
#include "../include/Board.h"

#include <vector>

using namespace std;

class Pawn : public Piece {
public:
    
    Pawn(Color color, int x, int y, Board* board) 
        : Piece(color, x, y, PieceType::Pawn, board, 10, 5, 60) {}
    
    bool move(int x1, int y1, int x2, int y2) override;
    // void promoteToQueen(int x, int y);

};
