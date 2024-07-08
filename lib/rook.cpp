#include "../include/rook.h"
#include "../include/king.h"

#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

bool Rook::move(int y1, int x1, int y2, int x2) {
    // Check if the move is within the board bounds
    if (!isInBounds(x2, y2)) 
    {
        return false;
    }

    std::cout << "Move from (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")" << std::endl;

    // Check if castling conditions are met and perform castling
    if (canCastle(x1, y1, x2, y2)) 
    {
        return true;
    }

    // Check if the destination square is occupied by a piece of the same color
    Piece* destPiece = board->getPiece(y2, x2);

    if (destPiece != nullptr && destPiece->getColor() == color) 
    {
        return false;
    }

    // Check if the move is a valid rook move (horizontal or vertical)
    if (x1 == x2) 
    { 
        int minY = std::min(y1, y2);
        int maxY = std::max(y1, y2);
        for (int y = minY + 1; y < maxY; y++) 
        {
            Piece* piece = board->getPiece(y, x1);
            if (piece != nullptr) 
            {
                return false;
            }
        }
    } 
    else if (y1 == y2) 
    { 
        int minX = std::min(x1, x2);
        int maxX = std::max(x1, x2);
        for (int x = minX + 1; x < maxX; x++) 
        {
            Piece* piece = board->getPiece(y1, x);
            if (piece != nullptr) 
            {
                return false;
            }
        }
    } 
    else 
    { 
        return false;
    }

    hasMoved = true;
    return true;
}

bool Rook::canCastle(int x1, int y1, int x2, int y2) {
    // Check if the rook has moved before
    if (hasMoved) 
    {
        return false;
    }

    // Check if the king has moved before
    if (king->hasMovedBefore()) 
    {
        return false;
    }

    if (y1 != y2) 
    {
        return false;
    }

    if ((color == Color::WHITE && y1 != 7 && y2 != 7) || (color == Color::BLACK && y1 != 0 && y2 != 0)) 
    {
        return false;
    }

    int minX = std::min(x1, x2);
    int maxX = std::max(x1, x2);

    for (int x = minX + 1; x < maxX; x++) 
    {
        if (board->getPiece(y1, x) != nullptr) 
        {
            return false;
        }
    }

    return true;
}