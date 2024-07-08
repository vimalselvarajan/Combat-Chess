#include "../include/king.h"

#include <cmath>

bool King::move(int y1, int x1, int y2, int x2) 
{
    if (isMoveValid(x1, y1, x2, y2)) 
    {
        // Update the position
        x = x2;
        y = y2;
        hasMoved = true; // Mark the king as moved
        return true;
    }
    
    return false;
}

bool King::isMoveValid(int x1, int y1, int x2, int y2) 
{
    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);

    // A King can move one square in any direction
    return (dx <= 1 && dy <= 1);
}

bool King::hasMovedBefore() const {
    return hasMoved;
}